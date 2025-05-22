.. SPDX-License-Identifier: GPL-2.0+:

.. index::
   single: fpga pr (command)

fpga pr command
===============

Synopsis
--------

::

    fpga pr <dev> <start|stop> <region>

Description
-----------

The *fpga pr* command is used to support partial reconfiguration functionality
on FPGA devices which support the same. General usage of the command would be
*fpga pr <dev> start <region>* followed by *fpga load* command, where partial
configuration image is loaded and stopping the operation with
*fpga pr <dev> stop <region>*.

dev
    device number

start
    starts the partial reconfiguration (pr) operation on the specified **pr** region

stop
    stops the partial reconfiguration (pr) operation on the specified **pr** region

region
    region number to undergo the partial reconfiguration operation

Return value
------------

The return value $? is set to 0 (true) if the operation is successful.

Example
-------

::

No console output is displayed when **pr** *start* and *stop* commands have been successful::

    => fpga pr 0 start 0

    => fpga pr 0 stop 0

However, desired output can be added to specific **pr** implementation functions.
For example, in case of Altera FPGA devices, following output is displayed. ::

    => fpga pr 0 start 0
    altera_freeze_br_req_ack request 1 acknowledged 1 ctrl 0

    => fpga pr 0 stop 0
    altera_freeze_br_req_ack request 2 acknowledged 2 ctrl 0

Configuration
-------------

The *fpga pr* command is only available if **CONFIG_CMD_FPGA_PR=y**.
