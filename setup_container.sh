#!/bin/bash

# This script updates submodules and dependencies

echo "Initializing submodules..."
./update_container.sh

echo "Downloading iPlug2 SDKs..."
cd iPlug2/Dependencies/IPlug/
./download-iplug-sdks.sh
cd ../../..

echo "Downloading iPlug2 prebuilt libs..."
cd iPlug2/Dependencies/
./download-prebuilt-libs.sh
cd ../..