#!/bin/bash

# This script initializes the cloned iPlug2OOS repo, downloading dependencies, 
# renaming the template and generating an SSL certificate using mkcert

if [ "$#" -eq 2 ]; then
    echo "Initializing submodule..."
    git submodule update --init
    
    echo "Downloading iPlug2 SDKs..."
    cd iPlug2/Dependencies/IPlug/
    ./download-iplug-sdks.sh
    cd ../../..

    echo "Duplicating template project..."
    python3 duplicate.py TemplateProject $1 $2
    rm -r TemplateProject
    git add $1
    git commit -a -m "Renamed template project"
    
    echo "Downloading mkcert..."
    wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.3/mkcert-v1.4.3-linux-amd64 -O mkcert
    chmod +x mkcert
    mv mkcert /usr/local/bin
    mkcert -install
else
    echo "usage: setup.sh PROJECT_NAME MANUFACTURER_NAME"
fi