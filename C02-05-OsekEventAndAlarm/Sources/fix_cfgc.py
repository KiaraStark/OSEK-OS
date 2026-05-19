import re

with open("d:\\yanyixia\\qianrushi\\实验代码\\C02-05-OsekEventAndAlarm\\Sources\\source\\cfg.c", "r", encoding='utf8') as f:
    text = f.read()

# 1. Fix OSEK_TASK_SUSPEND
text = text.replace(" | OSEK_TASK_SUSPEND", "")

# 2. Fix ResourcePriorityTable syntax
text = text.replace("{CONFIG_OSEK_TASK_PRIORITY_NUMBER - 1},", "CONFIG_OSEK_TASK_PRIORITY_NUMBER - 1,")
text = text.replace("{CONFIG_OSEK_TASK_PRIORITY_NUMBER - 1} ", "CONFIG_OSEK_TASK_PRIORITY_NUMBER - 1 ")

# 3. Check for any missing declarations (like T_OSEK_TASK_Entry)
# We will just write it back
with open("d:\\yanyixia\\qianrushi\\实验代码\\C02-05-OsekEventAndAlarm\\Sources\\source\\cfg.c", "w", encoding='utf8') as f:
    f.write(text)

print("done")
