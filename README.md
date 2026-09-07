# 🎬 Movie Ticket Booking System

A console-based **Movie Ticket Booking System developed in C++ using Object-Oriented Programming (OOP)** concepts.

The project simulates a real-world cinema ticket booking process where users can view movies, select shows, choose seats, make payments, generate tickets, and cancel confirmed bookings.

---

## 📌 Features

* 🎥 View available movies
* 🕐 View available shows and screens
* 💺 Display seat layout with seat categories
* 🎟️ Book one or multiple seats
* 💰 Automatic ticket price calculation
* 💳 Multiple payment options:

  * UPI
  * Card
  * Cash
* 🧾 Generate and display booking tickets
* ❌ Cancel confirmed bookings
* 🔄 Automatically make cancelled seats available again
* 📋 View all booking records
* 🔐 Reject bookings if seats are invalid or already booked

---

## 🛠️ Technologies Used

* **Language:** C++
* **Concept:** Object-Oriented Programming
* **Compiler:** g++
* **Platform:** Console / Terminal

---

## 🧠 OOP Concepts Used

This project is designed to demonstrate important Object-Oriented Programming concepts:

### 1. Encapsulation

Data members of classes are kept private and accessed through public member functions.

### 2. Abstraction

The `Payment` class is an abstract class that defines the common payment interface.

### 3. Inheritance

`UpiPayment`, `CardPayment`, and `CashPayment` inherit from the `Payment` class.

### 4. Polymorphism

Payment methods are handled using a `Payment*` pointer, allowing different payment implementations to be used through the same interface.

### 5. Composition

A `Cinema` owns its `Screen` objects, while a `ShowSeat` contains a `Seat`.

### 6. Aggregation

A `Show` refers to existing `Movie` and `Screen` objects without owning them.

### 7. Association

`Booking` maintains references to the `Show` and `Customer` involved in the booking.

### 8. Single Responsibility Principle

Different classes are responsible for different tasks:

* `PriceCalculator` → Calculates prices
* `TicketPrinter` → Prints tickets
* `BookingService` → Handles the booking workflow
* `Payment` → Defines the payment contract

---

## 🏗️ Project Structure

```text
Movie-Ticket-Booking/
│
├── 01_Movie.cpp
├── 02_Seat.cpp
├── 03_Screen.cpp
├── 04_Cinema.cpp
├── 05_Show.cpp
├── 06_ShowSeat.cpp
├── 07_Customer.cpp
├── 08_Booking.cpp
├── 09_Payment.cpp
├── 10_PaymentTypes.cpp
├── 11_PriceCalculator.cpp
├── 12_TicketPrinter.cpp
├── 13_BookingService.cpp
└── main.cpp
```

---

## 🎭 Main Classes

| Class             | Responsibility                                      |
| ----------------- | --------------------------------------------------- |
| `Movie`           | Stores movie title, language and duration           |
| `Seat`            | Stores physical seat number and category            |
| `Screen`          | Maintains seats available on a screen               |
| `Cinema`          | Manages cinema screens                              |
| `Show`            | Represents a movie screening on a particular screen |
| `ShowSeat`        | Maintains seat availability for a specific show     |
| `Customer`        | Stores customer information                         |
| `Booking`         | Stores booking details and status                   |
| `Payment`         | Abstract payment interface                          |
| `UpiPayment`      | Handles UPI payment                                 |
| `CardPayment`     | Handles card payment                                |
| `CashPayment`     | Handles cash payment                                |
| `PriceCalculator` | Calculates total ticket price                       |
| `TicketPrinter`   | Generates ticket output                             |
| `BookingService`  | Controls the complete booking workflow              |

---

## 💺 Seat Categories

The system provides three types of seats:

| Seat Type | Price |
| --------- | ----: |
| Silver    |  ₹150 |
| Gold      |  ₹250 |
| Platinum  |  ₹400 |

---

## 💳 Payment Methods

The system supports three payment methods:

```text
1. UPI
2. Card
3. Cash
```

The payment system uses **inheritance and runtime polymorphism**, allowing the booking service to work with different payment methods through the `Payment` base class.

---

## 🔄 Booking Flow

```text
View Movies
     ↓
Select Movie
     ↓
Select Show
     ↓
View Seat Layout
     ↓
Select Seats
     ↓
Check Seat Availability
     ↓
Calculate Total Price
     ↓
Select Payment Method
     ↓
Payment Successful?
    ↙       ↘
  YES        NO
   ↓          ↓
Book Seats   Booking Failed
   ↓
Generate Ticket
```

---

## ❌ Cancellation Flow

A confirmed booking can be cancelled using its Booking ID.

When a confirmed booking is cancelled:

* Booking status changes to `CANCELLED`
* Previously booked seats become `AVAILABLE`
* The seats can be booked again

---

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone <repository-url>
```

### 2. Open the project folder

```bash
cd Movie-Ticket-Booking
```

### 3. Compile the program

```bash
g++ main.cpp -o movie_booking
```

### 4. Run the program

```bash
./movie_booking
```

---

## 🖥️ Sample Menu

```text
===== MOVIE TICKET BOOKING =====
1. Movies  2. Book  3. Cancel  4. My tickets  0. Exit
Choose:
```

---

## 🎟️ Sample Ticket

```text
================ TICKET ================
Booking ID : BK1001
Movie      : 3 Idiots
Screen     : Screen-1   06:00 PM
Seats      : A1, B2
Amount     : Rs.400     Status: CONFIRMED
=========================================
```

---

## 🎯 Objective

The main objective of this project is to build a simple but structured movie ticket booking application while applying **real-world Object-Oriented Programming principles**.

The project focuses on designing independent classes with clear responsibilities and demonstrating relationships between objects such as **composition, aggregation, association, inheritance, abstraction, encapsulation, and polymorphism**.

---

## 🚀 Future Improvements

* Add a graphical user interface
* Add database connectivity
* Add user login and registration
* Add multiple cinema locations
* Add real-time show timings
* Integrate a real payment gateway
* Add booking history for individual users
* Add online movie and show management

---

## 👩‍💻 Author

**Kritika**

C++ | Object-Oriented Programming | Software Development

---

## 📄 License

This project is created for educational and academic purposes.
