Volume-list
=========
### Native C library to get information about mouted volume.

Notice that this module **does not require** admin privileges to get volume information in any supported operating system.

Supports:

- GNU/Linux distributions.
- Mac OS X.

## Install via [npm](https://npmjs.com)

```bash
$ npm install @pitzzae/volume-list --save
```

## Usage

```javascript
const VolumeList = require('@pitzzae/volume-list');
```

Get all mouted volumes

```javascript
let volume_list = VolumeList();
```

Output

```json
[
  {
    "size": 999995129856,
    "used": 509489152,
    "free": 999485640704,
    "mount": "/Volumes/Recovery",
    "device": "/dev/disk1s1",
    "fstype": "apfs"
  },
  {
    "size": 999995129856,
    "used": 11811192832,
    "free": 988183937024,
    "mount": "/private/var/vm",
    "device": "/dev/disk1s1",
    "fstype": "apfs"
  },
  {
    "size": 346112,
    "used": 346112,
    "free": 0,
    "mount": "/dev",
    "device": "/dev/disk1s1",
    "fstype": "apfs"
  },
  {
    "size": 999995129856,
    "used": 650876833792,
    "free": 349118296064,
    "mount": "/",
    "device": "/dev/disk1s1",
    "fstype": "apfs"
  }
]
```

Get size of specific list path

```javascript
let volume_list = VolumeList(["/tmp", "/"]);
```

Output

```json
[
  {
    "size": 999995129856,
    "used": 650875514880,
    "free": 349119614976,
    "path": "/"
  },
  {
    "size": 999995129856,
    "used": 650875514880,
    "free": 349119614976,
    "path": "/tmp"
  }
]
```

Support
-------

If you're having any problem, please [raise an issue](https://github.com/pitzzae/volume-list/issues/new) on GitHub.