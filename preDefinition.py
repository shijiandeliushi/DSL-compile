import datetime

# ==========================================
# 基础设备类
# ==========================================
class Device:
    def __init__(self, dev_id, alias):
        self.dev_id = dev_id
        self.alias = alias
        self.status = "off"

    def _validate(self, attr, val, min_v, max_v):
        if not (min_v <= val <= max_v):
            print(f"[警告] {self.alias}: {attr} 设定值 {val} 超出范围 [{min_v}, {max_v}]")
            return False
        return True

    def set_status(self, val):
        self.status = "on" if val in ["on", True, 1] else "off"
        print(f"[设备动作] {self.alias} -> 电源: {self.status.upper()}")

# ==========================================
# 具体设备类型实现
# ==========================================

class Light(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)
        self.brightness = 80

    def set_brightness(self, val):
        if self._validate("亮度", val, 0, 100):
            self.brightness = int(val)
            print(f"[设备动作] {self.alias} -> 亮度调节为: {self.brightness}%")

class AirConditioner(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)
        self.temperature = 26.0
        self.mode = 1 # 1:制冷, 2:制热, 3:送风

    def set_temperature(self, val):
        if self._validate("温度", val, 16.0, 30.0):
            self.temperature = float(val)
            print(f"[设备动作] {self.alias} -> 温度设定为: {self.temperature}℃")

    def set_mode(self, val):
        if self._validate("模式", val, 1, 3):
            self.mode = int(val)
            modes = {1: "制冷", 2: "制热", 3: "送风"}
            print(f"[设备动作] {self.alias} -> 模式切换为: {modes[self.mode]}")

class WaterHeater(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)
        self.target_temp = 45

    def set_target_temp(self, val):
        if self._validate("目标水温", val, 35, 75):
            self.target_temp = int(val)
            print(f"[设备动作] {self.alias} -> 目标水温设定为: {self.target_temp}℃")

class Television(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)
        self.volume = 20
        self.channel = 1

    def set_volume(self, val):
        if self._validate("音量", val, 0, 100):
            self.volume = int(val)
            print(f"[设备动作] {self.alias} -> 音量调节为: {self.volume}")

    def set_channel(self, val):
        if self._validate("频道", val, 1, 200):
            self.channel = int(val)
            print(f"[设备动作] {self.alias} -> 频道切换至: {self.channel}")

class Washer(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)
        self.mode = 1

    def set_mode(self, val):
        if self._validate("洗涤模式", val, 1, 4):
            self.mode = int(val)
            modes = {1: "标准", 2: "快洗", 3: "大件", 4: "脱水"}
            print(f"[设备动作] {self.alias} -> 模式设定为: {modes[self.mode]}")

class Fridge(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)
        self.fridge_temp = 4.0
        self.freezer_temp = -18.0

    def set_fridge_temp(self, val):
        if self._validate("冷藏温度", val, 0.0, 8.0):
            self.fridge_temp = float(val)
            print(f"[设备动作] {self.alias} -> 冷藏室设定为: {self.fridge_temp}℃")

    def set_freezer_temp(self, val):
        if self._validate("冷冻温度", val, -24.0, -15.0):
            self.freezer_temp = float(val)
            print(f"[设备动作] {self.alias} -> 冷冻室设定为: {self.freezer_temp}℃")

class ElectricFan(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)
        self.speed = 1
        self.oscillation = False

    def set_speed(self, val):
        if self._validate("风速", val, 1, 5):
            self.speed = int(val)
            print(f"[设备动作] {self.alias} -> 风速设定为: {self.speed}档")

    def set_oscillation(self, val):
        self.oscillation = bool(val)
        state = "开启" if self.oscillation else "关闭"
        print(f"[设备动作] {self.alias} -> 摆头功能: {state}")

# ==========================================
# 环境模拟与时间逻辑 (保持不变)
# ==========================================
def get_current_time_str():
    return datetime.datetime.now().strftime("%H:%M")

def is_time_between(start, end):
    return start <= get_current_time_str() <= end

def is_time_after(t): return get_current_time_str() >= t

def is_time_before(t): return get_current_time_str() <= t

def run_rule(rule_name, rule_func):
    print(f"\n>>> 激活规则: {rule_name}")
    rule_func()
    print(f">>> 规则 {rule_name} 执行完毕\n")

ON = "on"
OFF = "off"