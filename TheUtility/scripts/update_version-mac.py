#!/usr/bin/env python3

# this script will create/update info plist files based on config.h

import plistlib, os, sys, shutil

IPLUG2_ROOT = "../../iPlug2"

scriptpath = os.path.dirname(os.path.realpath(__file__))
projectpath = os.path.abspath(os.path.join(scriptpath, os.pardir))

kAudioUnitType_MusicDevice      = "aumu"
kAudioUnitType_MusicEffect      = "aumf"
kAudioUnitType_Effect           = "aufx"
kAudioUnitType_MIDIProcessor    = "aumi"

sys.path.insert(0, os.path.join(os.getcwd(), IPLUG2_ROOT + '/Scripts'))

from parse_config import parse_config, parse_xcconfig

def main():
  config = parse_config(projectpath)
  xcconfig = parse_xcconfig(os.path.join(os.getcwd(), IPLUG2_ROOT +  '/../common-mac.xcconfig'))

  CFBundleGetInfoString = config['BUNDLE_NAME'] + " v" + config['FULL_VER_STR'] + " " + config['PLUG_COPYRIGHT_STR']
  CFBundleVersion = config['FULL_VER_STR']
  CFBundlePackageType = "BNDL"
  CSResourcesFileMapped = True
  LSMinimumSystemVersion = xcconfig['DEPLOYMENT_TARGET']

  print("Processing Info.plist files...")

# VST3

  plistpath = projectpath + "/resources/" + config['BUNDLE_NAME'] + "-VST3-Info.plist"
  with open(plistpath, 'rb') as f:
    vst3 = plistlib.load(f)  
    vst3['CFBundleExecutable'] = config['BUNDLE_NAME']
    vst3['CFBundleGetInfoString'] = CFBundleGetInfoString
    vst3['CFBundleIdentifier'] = config['BUNDLE_DOMAIN'] + "." + config['BUNDLE_MFR'] + ".vst3." + config['BUNDLE_NAME'] + ""
    vst3['CFBundleName'] = config['BUNDLE_NAME']
    vst3['CFBundleVersion'] = CFBundleVersion
    vst3['CFBundleShortVersionString'] = CFBundleVersion
    vst3['LSMinimumSystemVersion'] = LSMinimumSystemVersion
    vst3['CFBundlePackageType'] = CFBundlePackageType
    vst3['CFBundleSignature'] = config['PLUG_UNIQUE_ID']
    vst3['CSResourcesFileMapped'] = CSResourcesFileMapped

    with open(plistpath, 'wb') as f2:
      plistlib.dump(vst3, f2)

# AUDIOUNIT v2

  plistpath = projectpath + "/resources/" + config['BUNDLE_NAME'] + "-AU-Info.plist"
  with open(plistpath, 'rb') as f:
    auv2 = plistlib.load(f)  
    auv2['CFBundleExecutable'] = config['BUNDLE_NAME']
    auv2['CFBundleGetInfoString'] = CFBundleGetInfoString
    auv2['CFBundleIdentifier'] = config['BUNDLE_DOMAIN'] + "." + config['BUNDLE_MFR'] + ".audiounit." + config['BUNDLE_NAME'] + ""
    auv2['CFBundleName'] = config['BUNDLE_NAME']
    auv2['CFBundleVersion'] = CFBundleVersion
    auv2['CFBundleShortVersionString'] = CFBundleVersion
    auv2['LSMinimumSystemVersion'] = LSMinimumSystemVersion
    auv2['CFBundlePackageType'] = CFBundlePackageType
    auv2['CFBundleSignature'] = config['PLUG_UNIQUE_ID']
    auv2['CSResourcesFileMapped'] = CSResourcesFileMapped

    if config['PLUG_TYPE'] == 0:
      if config['PLUG_DOES_MIDI_IN']:
        COMPONENT_TYPE = kAudioUnitType_MusicEffect
      else:
        COMPONENT_TYPE = kAudioUnitType_Effect
    elif config['PLUG_TYPE'] == 1:
      COMPONENT_TYPE = kAudioUnitType_MusicDevice
    elif config['PLUG_TYPE'] == 2:
      COMPONENT_TYPE = kAudioUnitType_MIDIProcessor

    auv2['AudioUnit Version'] = config['PLUG_VERSION_HEX']
    auv2['AudioComponents'] = [{}]
    auv2['AudioComponents'][0]['description'] = config['PLUG_NAME']
    auv2['AudioComponents'][0]['factoryFunction'] = config['AUV2_FACTORY']
    auv2['AudioComponents'][0]['manufacturer'] = config['PLUG_MFR_ID']
    auv2['AudioComponents'][0]['name'] = config['PLUG_MFR'] + ": " + config['PLUG_NAME']
    auv2['AudioComponents'][0]['subtype'] = config['PLUG_UNIQUE_ID']
    auv2['AudioComponents'][0]['type'] = COMPONENT_TYPE
    auv2['AudioComponents'][0]['version'] = config['PLUG_VERSION_INT']
    auv2['AudioComponents'][0]['sandboxSafe'] = True

    with open(plistpath, 'wb') as f2:
      plistlib.dump(auv2, f2)
      
# AUDIOUNIT v3

  if config['PLUG_HAS_UI']:
    NSEXTENSIONPOINTIDENTIFIER  = "com.apple.AudioUnit-UI"
  else:
    NSEXTENSIONPOINTIDENTIFIER  = "com.apple.AudioUnit"

  plistpath = projectpath + "/resources/" + config['BUNDLE_NAME'] + "-macOS-AUv3-Info.plist"

  with open(plistpath, 'rb') as f:
    auv3 = plistlib.load(f)  
    auv3['CFBundleExecutable'] = config['BUNDLE_NAME']
    auv3['CFBundleGetInfoString'] = CFBundleGetInfoString
    auv3['CFBundleIdentifier'] = config['BUNDLE_DOMAIN'] + "." + config['BUNDLE_MFR'] + ".app." + config['BUNDLE_NAME'] + ".AUv3"
    auv3['CFBundleName'] = config['BUNDLE_NAME']
    auv3['CFBundleVersion'] = CFBundleVersion
    auv3['CFBundleShortVersionString'] = CFBundleVersion
    auv3['LSMinimumSystemVersion'] = "10.12.0"
    auv3['CFBundlePackageType'] = "XPC!"
    auv3['NSExtension'] = dict(
    NSExtensionAttributes = dict(
                                AudioComponentBundle = "com.AcmeInc.app." + config['BUNDLE_NAME'] + ".AUv3Framework",
                                AudioComponents = [{}]),
  #                               NSExtensionServiceRoleType = "NSExtensionServiceRoleTypeEditor",
    NSExtensionPointIdentifier = NSEXTENSIONPOINTIDENTIFIER,
    NSExtensionPrincipalClass = "IPlugAUViewController"
                              )
    auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'] = [{}]
    auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['description'] = config['PLUG_NAME']
    auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['manufacturer'] = config['PLUG_MFR_ID']
    auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['name'] = config['PLUG_MFR'] + ": " + config['PLUG_NAME']
    auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['subtype'] = config['PLUG_UNIQUE_ID']
    auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['type'] = COMPONENT_TYPE
    auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['version'] = config['PLUG_VERSION_INT']
    auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['sandboxSafe'] = True
    auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['tags'] = [{}]

    if config['PLUG_TYPE'] == 1:
      auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['tags'][0] = "Synth"
    else:
      auv3['NSExtension']['NSExtensionAttributes']['AudioComponents'][0]['tags'][0] = "Effects"

    with open(plistpath, 'wb') as f2:
      plistlib.dump(auv3, f2)

if __name__ == '__main__':
  main()
