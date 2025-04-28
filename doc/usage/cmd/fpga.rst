.. SPDX-License-Identifier: GPL-2.0+

.. index::
   single: fpga pr (command)

fpga pr command
=============

Synopsis
--------

::

    fpga pr <dev> <start|stop> <region>

Description
-----------

The "fpga pr" command is used to provide basic functionality for partial reconfiguration on
FPGA devices which include the freeze controller support.

dev
    device number

start
    starts the partial reconfiguration (PR) process by freezing the specified PR region

stop
    stops the partial reconfiguration (PR) process by unfreezing the specified PR region

region
    region number to undergo the partial reconfiguration process

Configuration
-------------

The "fpga pr" command is only available on fpga devices.

Return value
------------

The return value $? is 0 (true).

Example
-------

::

Below console output is displayed when pr start and stop commands have been successful::

    => fpga pr 0 start 0
    PR operation successful

    => fpga pr 0 stop 0
    PR operation successful

Below console output is displayed when pr start and stop commands have failed::

    => fpga pr 0 start 0
    PR operation failed

    => fpga pr 0 stop 0
    PR operation failed
