iPlug2OOS simplified for creating VST3/AUv2 plugins from SOUL-VA effects.

# Features
- Support for 64-bit Metal/Non-Metal and x86/arm64 Macs
- SOUL code compiles pre-build when developing in Visual Studio

## Mac Distribution Folder
- Default - VST3/AU built on NanoVG/Metal
- Compatible -VST3/AU built on SKIA/CPU
- Readme.txt

## Mac Codesigning/Notarization
Define these secrets if you want to sign/notarize the Mac builds
- APPLE_ID
- APP_SPECIFIC_PWD
- CERTIFICATES_P12
- CERTIFICATES_P12_PASSWORD
- CERT_NAME_HASH
- TEAM_ID