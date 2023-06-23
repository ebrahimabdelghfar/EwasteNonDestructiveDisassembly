#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/resources"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/lib/python3/dist-packages:/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/resources/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/resources" \
    "/usr/bin/python3" \
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/resources/setup.py" \
     \
    build --build-base "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/resources" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install" --install-scripts="/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/bin"
