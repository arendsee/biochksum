# biochksum

Make a checksum for a FASTA file

# Description

Checksums are used regularly for confirming the identity of two files.
Often the md5sum is used. However, md5sum tests file identity, not
sequence identity. The purpose of this tool is to create a less stringent
checksum.

biochksum is unaffected by:

 1. the order of sequences in the FASTA file

 2. newlines within a sequence

 3. any content in the headers

 4. sequence character case

 5. any non-alphabetic characters (e.g. '*', '-')

Points 3-5 are debatable. I may in the future implement options for
alternative handling.

# Installation

No fancy dependencies, just `make` and run.

# Usage

No UI currently (I use a hardcoded file name).

# Hash function

My current hash function is pretty clunky. I won't bother to formally
describe it yet, since I won't be keeping it.
