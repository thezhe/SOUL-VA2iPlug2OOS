#! /bin/sh

# TheZhe Modifications
# - No args (full/zip hardcoded)
# - VST3/AU only with Default/Compatible builds
# - custom codesign/notarize

# this script requires xcpretty https://github.com/xcpretty/xcpretty

BASEDIR=$(dirname $0)

cd $BASEDIR/..

BUILDDIR=build-mac

if [ -d $BUILDDIR ]; then
  sudo rm -f -R $BUILDDIR
fi

#---------------------------------------------------------------------------------------------------------
echo "setting variables"
echo ""

# $PLUG_NAME
PLUG_NAME=TheExpressor

# $ARCHIVE_NAME
IPLUG2_ROOT=../iPlug2
XCCONFIG=$IPLUG2_ROOT/../common-mac.xcconfig
VERSION=`echo | grep PLUG_VERSION_HEX config.h`
VERSION=${VERSION//\#define PLUG_VERSION_HEX }
VERSION=${VERSION//\'}
MAJOR_VERSION=$(($VERSION & 0xFFFF0000))
MAJOR_VERSION=$(($MAJOR_VERSION >> 16))
MINOR_VERSION=$(($VERSION & 0x0000FF00))
MINOR_VERSION=$(($MINOR_VERSION >> 8))
BUG_FIX=$(($VERSION & 0x000000FF))
FULL_VERSION=$MAJOR_VERSION"."$MINOR_VERSION"."$BUG_FIX
ARCHIVE_NAME=$PLUG_NAME-$FULL_VERSION-mac

# $VST3 and $AU
VST3=`echo | grep VST3_PATH $XCCONFIG`
VST3=$HOME${VST3//\VST3_PATH = \$(HOME)}/$PLUG_NAME.vst3
AU=`echo | grep AU_PATH $XCCONFIG`
AU=$HOME${AU//\AU_PATH = \$(HOME)}/$PLUG_NAME.component
echo $VST3
echo $AU

# $MANUAL and $MANUAL_NAME
MANUAL="manual/README-mac.txt"
MANUAL_NAME="README.txt"

#---------------------------------------------------------------------------------------------------------
echo "REBUILDING DEFAULT VERSION+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo ""

echo "touching source to force recompile"
echo ""

touch *.cpp

echo "remove existing binaries"
echo ""

if [ -d $AU ]; then
 sudo rm -f -R $AU
fi

if [ -d $VST3 ]; then
  sudo rm -f -R $VST3
fi

echo "rebuilding"
echo ""

xcodebuild -project ./projects/$PLUG_NAME-macOS.xcodeproj -xcconfig ./config/$PLUG_NAME-mac-Default.xcconfig DEMO_VERSION=0 -target VST3 -target AU -UseModernBuildSystem=NO -configuration Release | tee $BUILDDIR.log | xcpretty #&& exit ${PIPESTATUS[0]}

if [ "${PIPESTATUS[0]}" -ne "0" ]; then
  echo "ERROR: Default build failed, aborting"
  echo ""
  cat $BUILDDIR.log
  exit 1
else
  rm $BUILDDIR.log
fi

echo "stripping binaries"
echo ""

if [ -d $AU ]; then
  strip -x $AU/Contents/MacOS/$PLUG_NAME
fi

if [ -d $VST3 ]; then
  strip -x $VST3/Contents/MacOS/$PLUG_NAME
fi

echo "moving Default build to $BUILDDIR/zip/Default"
echo ""

if [ -d $BUILDDIR/zip/Default ]; then
  rm -R $BUILDDIR/zip/Default
fi

mkdir -p $BUILDDIR/zip/Default

if [ -d $AU ]; then
  cp -R $AU $BUILDDIR/zip/Default/$PLUG_NAME.component
fi

if [ -d $VST3 ]; then
  cp -R $VST3 $BUILDDIR/zip/Default/$PLUG_NAME.vst3
fi

echo "$BUILDDIR/zip/Default"
echo ""
ls $BUILDDIR/zip/Default

#---------------------------------------------------------------------------------------------------------
echo "REBUILDING COMPATIBLE VERSION+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo ""

echo "touching source to force recompile"
echo ""

touch *.cpp

echo "remove existing binaries"
echo ""

if [ -d $AU ]; then
 sudo rm -f -R $AU
fi

if [ -d $VST3 ]; then
  sudo rm -f -R $VST3
fi

echo "rebuilding"
echo ""

xcodebuild -project ./projects/$PLUG_NAME-macOS.xcodeproj -xcconfig ./config/$PLUG_NAME-mac-Compatible.xcconfig DEMO_VERSION=0 -target VST3 -target AU -UseModernBuildSystem=NO -configuration Release | tee $BUILDDIR.log | xcpretty #&& exit ${PIPESTATUS[0]}

if [ "${PIPESTATUS[0]}" -ne "0" ]; then
  echo "ERROR: Compatible build failed, aborting"
  echo ""
  cat $BUILDDIR.log
  exit 1
else
  rm $BUILDDIR.log
fi

echo "stripping binaries"
echo ""

if [ -d $AU ]; then
  strip -x $AU/Contents/MacOS/$PLUG_NAME
fi

if [ -d $VST3 ]; then
  strip -x $VST3/Contents/MacOS/$PLUG_NAME
fi

echo "moving Compatible build to $BUILDDIR/zip/Compatible"
echo ""

if [ -d $BUILDDIR/zip/Compatible ]; then
  rm -R $BUILDDIR/zip/Compatible
fi

mkdir -p $BUILDDIR/zip/Compatible

if [ -d $AU ]; then
  cp -R $AU $BUILDDIR/zip/Compatible/$PLUG_NAME.component
fi

if [ -d $VST3 ]; then
  cp -R $VST3 $BUILDDIR/zip/Compatible/$PLUG_NAME.vst3
fi

echo "$BUILDDIR/zip/Compatible"
echo ""
ls $BUILDDIR/zip/Compatible

#---------------------------------------------------------------------------------------------------------
echo "moving manual to $BUILDDIR/zip"
echo ""

if [ -e $MANUAL ]; then
  cp -R $MANUAL $BUILDDIR/zip/$MANUAL_NAME
fi

echo "$BUILDDIR/zip"
echo ""
ls $BUILDDIR/zip

#---------------------------------------------------------------------------------------------------------
echo "setting up sign/notarize"
echo ""

security find-identity -p codesigning
xcrun notarytool store-credentials "AC_PASSWORD" --apple-id $APPLE_ID --team-id $TEAM_ID --password $APP_SPECIFIC_PWD

echo "signing"
echo ""

xattr -cr $BUILDDIR/zip/Default/$PLUG_NAME.component
codesign --force -s $CERT_NAME_HASH -v $BUILDDIR/zip/Default/$PLUG_NAME.component --deep --strict --options=runtime --timestamp
xattr -cr $BUILDDIR/zip/Default/$PLUG_NAME.vst3
codesign --force -s $CERT_NAME_HASH -v $BUILDDIR/zip/Default/$PLUG_NAME.vst3 --deep --strict --options=runtime --timestamp
xattr -cr $BUILDDIR/zip/Compatible/$PLUG_NAME.component
codesign --force -s $CERT_NAME_HASH -v $BUILDDIR/zip/Compatible/$PLUG_NAME.component --deep --strict --options=runtime --timestamp
xattr -cr $BUILDDIR/zip/Compatible/$PLUG_NAME.vst3
codesign --force -s $CERT_NAME_HASH -v $BUILDDIR/zip/Compatible/$PLUG_NAME.vst3 --deep --strict --options=runtime --timestamp

echo "notarizing..."
echo ""

ditto -c -k $BUILDDIR/zip $BUILDDIR/$ARCHIVE_NAME.zip
xcrun notarytool submit $BUILDDIR/$ARCHIVE_NAME.zip --keychain-profile "AC_PASSWORD" --wait  

xcrun stapler staple $BUILDDIR/zip/Default/$PLUG_NAME.component            
xcrun stapler staple $BUILDDIR/zip/Default/$PLUG_NAME.vst3       
xcrun stapler staple $BUILDDIR/zip/Compatible/$PLUG_NAME.component            
xcrun stapler staple $BUILDDIR/zip/Compatible/$PLUG_NAME.vst3            

rm -R $BUILDDIR/$ARCHIVE_NAME.zip

#---------------------------------------------------------------------------------------------------------
echo "moving $BUILDDIR/zip contents to $BUILDDIR/$ARCHIVE_NAME.zip"
echo ""

ditto -c -k $BUILDDIR/zip $BUILDDIR/$ARCHIVE_NAME.zip
rm -R $BUILDDIR/zip

echo "moving ./$BUILDDIR/*.zip to ./$BUILDDIR/out"
echo ""

mkdir -p ./$BUILDDIR/out
mv ./$BUILDDIR/*.zip ./$BUILDDIR/out

echo "DONE!"
echo ""