import datetime
import time

# ==========================================
# 基础设备类
# ==========================================
class Device:
    def __init__(self, dev_id, alias):
        self.dev_id = dev_id
        self.alias = alias
        self.is_on = False
        self.value = 0.0

    def set_status(self, status):
        """处理 on/off"""
        if isinstance(status, str):
            self.is_on = (status.lower() == 'on')
        else:
            self.is_on = bool(status)
        state_str = "开启" if self.is_on else "关闭"
        print(f"[状态更新] {self.alias} ({self.dev_id}) -> {state_str}")

    def set_value(self, val):
        """处理数值设定（如温度、亮度等）"""
        self.value = float(val)
        print(f"[数值更新] {self.alias} ({self.dev_id}) -> 设定值为: {self.value}")

# ==========================================
# 具体设备类型实现
# ==========================================
class Light(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)

class AirConditioner(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)
        self.temperature = 26.0

class WaterHeater(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)

class Television(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)

class Washer(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)

class Fridge(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)

class ElectricFan(Device):
    def __init__(self, dev_id, alias):
        super().__init__(dev_id, alias)

# ==========================================
# 环境模拟与时间逻辑
# ==========================================

# 模拟全局环境变量
temperature = 25.0  # 对应 HomeLang 中的 temperature 关键字
duration = 0        # 对应 HomeLang 中的 duration 关键字

def get_current_time_str():
    """获取当前时间字符串 "HH:MM" """
    return datetime.datetime.now().strftime("%H:%M")

def is_time_between(start_str, end_str):
    """判断当前时间是否在范围内"""
    now = get_current_time_str()
    return start_str <= now <= end_str

def is_time_after(time_str):
    return get_current_time_str() > time_str

def is_time_before(time_str):
    return get_current_time_str() < time_str

def is_day_of_week(allowed_days):
    """判断今天是否在指定的星期列表中 ['mon', 'tue'...]"""
    # Python %a 返回 Mon, Tue...
    today = datetime.datetime.now().strftime("%a").lower()
    return today in [d.lower() for d in allowed_days]

# ==========================================
# 规则执行引擎
# ==========================================
def run_rule(rule_name, rule_func):
    print(f"\n>>> 激活规则: {rule_name}")
    try:
        rule_func()
    except Exception as e:
        print(f"规则执行出错: {e}")
    print(f">>> 规则 {rule_name} 执行完毕\n")

# 辅助映射（用于代码生成器）
ON = "on"
OFF = "off"