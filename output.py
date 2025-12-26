from preDefinition import *
import datetime

# 补充生成的辅助函数
def is_time_after(t): return get_current_time_str() >= t
def is_time_before(t): return get_current_time_str() <= t

parlour_electric_fan = ElectricFan('parlour_electric_fan','客厅电风扇')
corridor_light = Light('corridor_light','走廊灯')
counter = 0
counter = 0

def rule_loop_test():
    global counter
    while counter < 3:
        corridor_light.set_status('on')
        corridor_light.set_status('off')
        counter = counter + 1
    parlour_electric_fan.set_status('on')
    for i in range(1, 6):
        parlour_electric_fan.set_speed(i)
    if is_time_between('22:00', '23:00'):
        parlour_electric_fan.set_oscillation(0)

# 执行规则
run_rule('loop_test', rule_loop_test)