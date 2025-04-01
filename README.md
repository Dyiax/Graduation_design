# 🌟 基于物联网的智能照明系统设计

## 🚀 项目简介

本项目设计并实现了一套**基于物联网的智能照明系统**，融合环境感知、AI决策与低碳管理，解决传统照明系统高能耗、低灵活性问题。系统通过动态调光、用户行为学习和Li-Fi通信技术，实现智能化、低功耗的照明控制，响应“双碳”目标。

**核心功能亮点** ✨：

- 🌞 **环境自适应调光**：实时感知光照、人体活动，动态调节亮度/色温
- 🧠 **AI行为学习**：LSTM模型预测用户习惯，生成个性化照明策略
- 💡 **Li-Fi通信**：利用可见光传输数据，定位精度≤0.5m
- 🌍 **碳排可视化**：统计能耗与碳排放，助力绿色建筑

## 📋 系统架构

### 1. 硬件层

- **主控芯片**：STM32F103C8T6
- **传感器**：DHT22（温湿度）、BH1750（光照）、HC-SR501（人体红外）
- **通信模块**：ESP8266（Wi-Fi）、
- **调光电路**：PWM驱动LED灯带

### 2. 软件层

- **用户终端**：跨平台APP（支持语音控制、数据可视化）
- **云端平台**：ThingsBoard（数据存储+异常预警）
- **智能算法**：TensorFlow Lite轻量化LSTM模型

### 3. 数据库设计

```sql
-- 传感器数据表
CREATE TABLE SensorData (
    SensorData_id INT PRIMARY KEY,
    timestamp DATETIME,
    temperature FLOAT,
    humidity FLOAT,
    light_intensity FLOAT
);

-- 用户习惯表
CREATE TABLE UserHabits (
    UserHabit_id INT PRIMARY KEY,
    user_id INT,
    work_time TIME,
    preferred_temperature FLOAT,
    preferred_light_intensity FLOAT
);
```


## 🔧 技术栈


| 模块     | 技术/工具                              |
| -------- | -------------------------------------- |
| 硬件开发 | STM32CubeMX, Keil MDK, Altium Designer |
| 通信协议 | MQTT, UDP, 自定义Li-Fi协议             |
| 云端服务 | ThingsBoard, 阿里云IoT                 |
| 移动端   | Flutter (Android/iOS)                  |
| AI算法   | TensorFlow Lite (LSTM)                 |

## 📌 性能指标

✅ **实时性**：人体感应响应≤200ms
✅ **节能率**：较传统系统提升≥40%
✅ **精度**：光照测量误差±5%，Li-Fi定位误差≤0.5m
✅ **稳定性**：72小时连续运行零宕机

## 🛠️ 快速开始

### 硬件部署

1. 焊接STM32主控板与传感器模块
2. 刷写固件（`/firmware/stm32_lighting.bin`）
3. 配置ESP8266连接MQTT Broker

### 软件运行

```
# 克隆仓库
git clone https://github.com/your-repo/smart-lighting.git

# 启动Flutter APP
cd app && flutter run
```

## 🌈 项目创新点

* **多技术融合**：首次将Li-Fi通信与动态调光结合
* **双碳实践**：碳排放可视化+峰谷电价响应
* **模块化设计**：支持扩展PM2.5/安防模块

## 📅 开发进度


| 阶段     | 时间    | 完成内容               |
| -------- | ------- | ---------------------- |
| 需求分析 | 2025.03 | 确定硬件选型与功能指标 |
| 硬件开发 | 2025.04 | PCB设计、传感器集成    |
| 软件开发 | 2025.05 | APP与云端平台联调      |
| 论文撰写 | 2025.06 | 系统测试与优化         |

## 📚 相关文献

1. 王伟, 李强. 《基于STM32的物联网智能家居系统设计》
2. IEEE 802.15.7: Visible Light Communication Standard

## 🤝 参与贡献

欢迎提交Issue或Fork改进！
📧 联系邮箱：[2079198609@qq.com]
