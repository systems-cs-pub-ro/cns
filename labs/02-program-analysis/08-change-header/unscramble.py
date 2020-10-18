#!/usr/bin/env python

import stat, os
import struct

try:
    from solution import *
except ImportError:
    pass

def transform_data(data, offset, value):
    assert(type (value) == list)
    assert(type (value) == list)
    assert(type (offset) == int or type (offset) == long)

    norm = []
    for b in value:
        new_b = b
        if type(b) == str:
            new_b = ord(b)
        assert(new_b < 256)
        norm.append(new_b)

    data_len = len(value)
    new_data = data[:offset]+norm+data[offset+data_len:]
    return new_data

def main():
    IN = './main.bad'
    OUT = './main.ok'

    apply_changes(IN, OUT, change_header)


def apply_changes(in_file, out_file, change_func):
    with open(in_file, 'rb') as f:
        data = list(f.read())

    data = change_func(data)

    with open(out_file, 'wb') as f:
        data = bytes(data)
        f.write(data)

    os.chmod(out_file, stat.S_IRWXU)

def change_header(data):
    ##### the magic values
    ELF_MAGIC_OFFSET
    ELF_MAGIC_BYTES
    data = transform_data(data, \
            ELF_MAGIC_OFFSET, ELF_MAGIC_BYTES)

    ##### some extra fields
    ELF_CLASS_OFFSET
    ELF_CLASS_BYTES
    data = transform_data(data, \
            ELF_CLASS_OFFSET, ELF_CLASS_BYTES)

    ELF_EI_DATA_OFFSET
    ELF_EI_DATA_BYTES
    data = transform_data(data, \
            ELF_EI_DATA_OFFSET, ELF_EI_DATA_BYTES)

    ##### set the entry point
    ELF_ENTRY_OFFSET
    # orig entry_point
    ELF_ENTRY_BYTES
    # main
    ELF_ENTRY_BYTES
    # call_me
    ELF_ENTRY_BYTES
    data = transform_data(data, \
            ELF_ENTRY_OFFSET, ELF_ENTRY_BYTES)
    return data

if __name__ == '__main__':
    main()
