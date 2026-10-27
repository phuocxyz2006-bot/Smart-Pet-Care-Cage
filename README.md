# 🐾 Smart Pet Care Cage - Lồng Thú Cưng Thông Minh

Dự án nguyên mẫu (prototype) hệ thống lồng chăm sóc thú cưng tự động sử dụng vi điều khiển Arduino Uno R3. Hệ thống tích hợp theo dõi nhiệt độ/độ ẩm, đếm số lần thú cưng hoạt động, tự động xả thức ăn khi hết và cảnh báo khi hết nước uống.

## 🌟 Tính năng chi tiết theo Code

* **Đếm số lần hoạt động (PIR Motion Sensor):** 
  - Đọc tín hiệu từ cảm biến chuyển động `HC-SR501`.
  - Mỗi khi thú cưng di chuyển qua, bật đèn LED1 (Pin 12) và cộng tích lũy số lần hoạt động (`activityCount`).
* **Theo dõi môi trường & Hiển thị LCD (I2C):**
  - Đọc nhiệt độ và độ ẩm từ cảm biến `DHT11`.
  - Hiển thị luôn phiên trên màn hình LCD 16x2 (địa chỉ I2C `0x27`): chuyển đổi giữa màn hình **Nhiệt độ/Độ ẩm** và màn hình **Đếm hoạt động thú cưng**.
* **Cảnh báo mực nước thông minh:**
  - Cấp nguồn tiết kiệm điện cho cảm biến nước qua chân Digital (Pin 5).
  - Đọc giá trị Analog mực nước (Pin A2). Nếu mực nước `< 15` (sắp hết/hết nước), hệ thống sẽ bật LED2 (Pin 13) và còi Buzzer kêu bíp 3 lần liên tục để báo động.
* **Tự động tiếp thức ăn (LoadCell HX711 + Servo):**
  - Cân khối lượng thức ăn còn lại trong khay bằng cảm biến LoadCell + HX711.
  - Khi khối lượng thức ăn `<= 0` (hết thức ăn): Servo tự động quay góc `180°` để mở cửa/xả thức ăn.
  - Khi lượng thức ăn đã đủ `> 0.5`: Servo quay về góc `90°` để đóng cửa khay.

---

## 🔌 Bảng sơ đồ kết nối chân chuẩn (Pinout)

<img width="3000" height="2682" alt="circuit_image (2)" src="https://github.com/user-attachments/assets/237f29c9-16cc-4f66-b294-4db614313de4" />

| Linh kiện / Module | Chân Linh Kiện | Chân Arduino Uno | Ghi chú |
| :--- | :---: | :---: | :--- |
| **Cảm biến PIR (HC-SR501)** | OUT | **D2** | Phát hiện chuyển động |
| **Cảm biến DHT11** | DATA | **D4** | Đo nhiệt độ / độ ẩm |
| **Cảm biến Mực nước** | Power (VCC) <br> Signal (OUT) | **D5** <br> **A2** | Cấp nguồn chủ động & đọc Analog |
| **Cân HX711 (Loadcell)** | DOUT <br> SCK | **D7** <br> **D8** | Đọc khối lượng thức ăn |
| **Còi báo động (Buzzer)** | Positive (+) | **D9** | Báo động khi hết nước |
| **Động cơ Servo (SG90)** | Signal (Cam/Vàng) | **D10** | Đóng/mở cửa xả thức ăn |
| **LED 1 (Báo chuyển động)** | Anode (+) | **D12** | Sáng khi có chuyển động |
| **LED 2 (Báo hết nước)** | Anode (+) | **D13** | Sáng khi nước trong bình hết |
| **Màn hình LCD 16x2 I2C** | SDA <br> SCL | **A4** <br> **A5** | Địa chỉ I2C: `0x27` |

*(Lưu ý: Tất cả các chân VCC 5V và GND của các linh kiện đều được nối chung về nguồn 5V và GND của Arduino).*

---

## 🚀 Thư viện Arduino cần cài đặt

Trước khi nạp code, hãy đảm bảo mày đã cài đủ các thư viện sau trong Arduino IDE (**Tools -> Manage Libraries**):

1. `HX711_ADC` (Bởi Olav Kallhovd)
2. `Servo` (Thư viện chuẩn có sẵn)
3. `DHT sensor library` (Bởi Adafruit)
4. `LiquidCrystal_I2C` (Bởi Frank de Brabander)
5. `Wire` (Thư viện chuẩn có sẵn)


