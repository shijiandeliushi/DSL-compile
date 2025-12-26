from preDefinition import *
import datetime

living_room_ac = AirConditioner('living_room_ac','客厅空调')
corridor_light = Light('corridor_light','走廊灯')
bedroom_fan = ElectricFan('bedroom_fan','卧室风扇')
temp = 0
humidity = 0
retry_count = 0
system_on = 0
night_mode = 0
temp = 32
humidity = 85
retry_count = 0
system_on = True
night_mode = False

def rule_deep_nested_logic():
    global temp, humidity, retry_count, system_on, night_mode
    if system_on == True:
        if temp > 30:
            living_room_ac.set_temperature(24)
            while retry_count < 3:
                if humidity > 80:
                    for i in range(1, 6):
                        corridor_light.set_status('on')
                        corridor_light.set_status('off')
                    bedroom_fan.set_status('on')
                retry_count = retry_count + 1
        if night_mode == True:
            corridor_light.set_status('on')

# 执行规则
run_rule('deep_nested_logic', rule_deep_nested_logic)