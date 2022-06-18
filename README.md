iPlug2OOS simplified for creating VST3/AUv2 plugins from SOUL-VA effects.

# Features
- Support for 64-bit Metal/Non-Metal and x86/arm64 Macs
- SOUL code compiles pre-build when developing in Visual Studio

# Use case
- Compile SOUL to C++ and test GUI/VST3PluginTestHost locally
- Release builds and unit testing using GitHub actions

## Mac Distribution Folder
- Default - VST3/AU built on NanoVG/Metal
- Compatible -VST3/AU built on SKIA/CPU
- Readme.txt

# Secrets
This repo uses [GitHub secrets](https://docs.github.com/en/actions/security-guides/encrypted-secrets) for both sensitive information and convenience. Undefined secrets won't break your builds, but will break signing/notarization and auval tests.

## auval
- MFR_ID (same as `PLUG_MFR_ID` in each plugin's config.h file)
##### NOTE: This repo is geared towards effect plugins. If you are not making effects (e.g., you're making midi instruments, you need to change replace 'aufx' in .github/workflows/build-native.yml as well as change .cpp and .h files accordingly)

## Mac Signing/Notarization
The following is information from an [apple developer account](https://developer.apple.com/) in the Apple Developer Program. 

- APPLE_ID
- [APP_SPECIFIC_PWD](https://support.apple.com/en-us/HT204397#:~:text=Sign%20in%20to%20appleid.apple,%2C%20click%20App%2DSpecific%20Passwords.&text=%2C%20then%20follow%20the%20steps%20on%20your%20screen.)
- CERTIFICATES_P12: your Developer ID Application certificate [converted from .p12 to base64 format](https://localazy.com/blog/how-to-automatically-sign-macos-apps-using-github-actions)
- CERTIFICATES_P12_PASSWORD (your .p12's password)
- CERT_NAME_HASH (your .p12's hash; find it by running `security find-identity -v -p codesigning` after the .p12 is imported)
- TEAM_ID

