echo "Need admin password to install packages"
sudo apt-get install libsdl1.2-dev libfontconfig1-dev libgconf2-dev libgtk2.0-dev libsdl-ttf2.0-dev yasm libqt4-dev aria2
MACHINE_TYPE=`uname -m`
if [ ${MACHINE_TYPE} == 'x86_64' ]; then
	sudo apt-get install libfontconfig1:i386 libpng12-0:i386 libasound2:i386 libqt4-gui:i386 libsdl1.2debian:i386 libSDL-ttf2.0-0:i386 libxinerama1:i386
fi

