# 🐾 Smart Pet Care Cage - Lồng Thú Cưng Thông Minh

Dự án nguyên mẫu (prototype) hệ thống chăm sóc thú cưng tự động sử dụng vi điều khiển Arduino Uno. Hệ thống giúp theo dõi môi trường sống, kiểm soát lượng thức ăn và giám sát hoạt động của thú cưng theo thời gian thực.

## 🌟 Tính năng chính
* **Theo dõi môi trường:** Đo nhiệt độ và độ ẩm bên trong lồng (DHT11).
* **Quản lý lượng thức ăn:** Cân và kiểm tra khối lượng thức ăn còn lại trong khay (Loadcell + HX711).
* **Tự động hóa & Cảnh báo:** 
  - Phát hiện thú cưng di chuyển (PIR Motion Sensor).
  - Tự động đóng/mở khay thức ăn (Servo Motor).
  - Còi báo động (Buzzer) khi có sự cố hoặc hết thức ăn/nước.
* **Cảnh báo mực nước:** Giám sát khay nước uống bằng cảm biến.
* **Hiển thị trực quan:** Toàn bộ trạng thái được xuất ra màn hình LCD (giao tiếp I2C).

## 🛠 Phần cứng sử dụng
- Vi điều khiển: Arduino Uno
- Hiển thị: Màn hình LCD 16x2 + Module I2C
- Cảm biến: DHT11, PIR HC-SR501, Cảm biến mực nước/độ ẩm đất
- Cân điện tử: Loadcell + Module khuếch đại HX711
- Cơ cấu chấp hành: Động cơ Servo SG90, Loa Buzzer

## 🔌 Sơ đồ chân kết nối (Pinout)

*Kéo thả file ảnh sơ đồ mạch điện (circuit_image) của mày vào dòng dưới này:*
<!-- CHÈN ẢNH SƠ ĐỒ VÀO ĐÂY -->

**Bảng đấu nối chi tiết với Arduino Uno:**

| Linh kiện | Chân linh kiện | Chân Arduino Uno |
| :--- | :---: | :---: |
| **Màn hình LCD I2C** | SDA <br> SCL | A4 <br> A5 |
| **Cảm biến PIR** | Data (OUT) | D2 |
| **Cảm biến DHT11** | Data (OUT) | D3 |
| **Loa Buzzer** | Chân dương (+) | D4 |
| **Cân HX711** | SCK <br> DT | D5 <br> D6 |
| **Động cơ Servo** | Signal (Cam/Vàng) | D9 |
| **Cảm biến Mực nước** | Analog Out | A0 |

*(Lưu ý: Tất cả các chân VCC cấp nguồn 5V và chân GND nối chung với Arduino)*

## 🚀 Hướng dẫn cài đặt và sử dụng
1. Mở file source code (`.ino`) bằng phần mềm **Arduino IDE**.
2. Cài đặt các thư viện cần thiết qua Library Manager:
   - `LiquidCrystal_I2C` (Cho màn hình LCD)
   - `DHT sensor library` (Cho cảm biến DHT11)
   - `HX711_ADC` hoặc `HX711` (Cho cảm biến cân nặng)
   - `Servo` (Có sẵn trong Arduino IDE)
3. Cắm cáp USB kết nối Arduino với máy tính.
4. Chọn đúng Board (`Arduino Uno`) và cổng COM tương ứng.
5. Bấm **Upload** để nạp code và mở Serial Monitor (Baudrate: 9600) để theo dõi song song (nếu cần).
<img width="3000" height="2682" alt="circuit_image (2)" src="https://github.com/user-attachments/assets/237f29c9-16cc-4f66-b294-4db614313de4" />

