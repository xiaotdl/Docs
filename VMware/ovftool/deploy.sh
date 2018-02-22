cat deploy.sh
#!/bin/bash

VMNAME=$1

die() {
        echo "$1"
        exit 1
}


set -x
ovftool --acceptAllEulas  \
            --noSSLVerify \
            --name="${VMNAME-${VERSION}}" \
                -ds="${VCENTER_DATASTORE}" \
                --net:"backend"="${VCENTER_BACKENDNETWORK}" \
                --net:"frontend"="${VCENTER_FRONTENDNETWORK}" \
                --powerOn \
                $OVA \
                "vi://${VCENTER_USER}:${VCENTER_PASSWORD}@${VCENTER_HOST}/${VCENTER_RESOURCEPOOL}"

set +x
