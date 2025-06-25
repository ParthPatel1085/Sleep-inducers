# Sleep-inducers


📝 Project Description
-----------------------
Sleep‑Inducers: Soothing Music System for Hostel Inmates  
This project is a C++ application that helps hostel inmates fall asleep by playing personalized, soothing music based on their individual sleep schedules. It manages multiple audio channels and assigns music to users until they drift off.

🔍 Project Overview
-----------------------
Sleep‑Inducers is designed to simulate a real-world solution for promoting restful sleep in a shared-living environment like a hostel. Built in C++, the system orchestrates audio channel management to cater to multiple users simultaneously without disturbances. The workflow includes:

- Inmate and Dorm Modeling: Reads sleep schedules and dorm-room assignments from CSV files (e.g., Input_for_Inmates.csv).
- Channel Allocation: Maintains a limited set of audio channels per dorm; each inmate is connected to a designated channel via earphones.
- Personalized Playback: Triggers sleep-inducing music for each inmate at their bedtime.
- Release Logic: Automatically stops music once an inmate is asleep (after a specified duration) and frees the channel for others.
- Concurrency Management: Ensures multiple inmates across dorms are managed efficiently without overlapping or disturbing sleeping users.

By handling input parsing, scheduling, channel allocation, and playback timing, this project demonstrates practical skills in file I/O, data structures (queues/lists), timing logic, and resource management in C++.

