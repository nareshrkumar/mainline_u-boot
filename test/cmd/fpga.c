// SPDX-License-Identifier: GPL-2.0+
/*
 * Tests for fpga commands
 *
 * Copyright (C) 2025 Altera Corporation <www.altera.com>
 */

#include <test/cmd.h>
#include <test/ut.h>

static int cmd_test_fpga_pr(struct unit_test_state *uts)
{
        ut_assertok(run_commandf("fpga pr 0 start 0"));
        ut_assertok(run_commandf("fpga pr 0 stop 0"));

        return 0;
}
CMD_TEST(cmd_test_fpga_pr, UTF_CONSOLE);
 