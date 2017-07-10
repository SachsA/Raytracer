#!/bin/bash
##
## installer.sh for raytracer2 in /rendu/Infographie/raytracer2
##
## Made by Thomas Lombard
## Login   <lombar_e@epitech.net>
##
## Started on  Wed May 03 09:18:13 2017 Thomas Lombard
## Last update Fri May 12 18:42:08 2017 Theodore Marestin
##

SOURCE='https://nodejs.org/dist/v7.9.0/node-v7.9.0-linux-x64.tar.xz'
FILE='node-v7.9.0-linux-x64.tar.xz'
EXTRACT_DIR='node-v7.9.0-linux-x64'

INSTALL_DIR='/usr/'
NODE_LOCATION='/usr/bin/node'
NPM_LOCATION='/usr/bin/npm'

# sed -r 's#DEFAULT_NODE(\s)[a-zA-Z]*("[/a-z]*")#DEFAULT_NODE\1"coucou"#gi'

if [ "$(type -P nodej)" != "" ]; then
    echo sed -r -i.bak 's#DEFAULT_NODE(\s)[a-zA-Z]*("[/a-z]*")#DEFAULT_NODE\1"'$(type -P node)'"#gi' includes/config.h
    exit 0
else
    wget "$SOURCE" -O "$FILE"
    tar xJf "$FILE"
    if [[ "$USER" == root ]]; then
        cp "$EXTRACT_DIR"/bin/* /usr/bin/
        cp -rf "$EXTRACT_DIR"/lib/* /usr/lib/
        cp -rf "$EXTRACT_DIR"/share/* /usr/share/
        sed -r -i.bak 's#DEFAULT_NODE(\s)[a-zA-Z]*("[/a-z]*")#DEFAULT_NODE\1"'"$(type -P node)"'"#gi' includes/config.h
    else
        mkdir -p .node
        cp -rf "$EXTRACT_DIR"/bin .node/
        cp -rf "$EXTRACT_DIR"/lib .node/
        cp -rf "$EXTRACT_DIR"/share .node/
        sed -r -i.bak 's#DEFAULT_NODE([ \t]*)"[a-z/]*"#DEFAULT_NODE\1".node/bin/node"#gi' includes/config.h
    fi
    rm -f includes/config.h.bak
    rm -rf "$EXTRACT_DIR" "$FILE"
fi
