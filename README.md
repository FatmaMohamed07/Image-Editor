# Image Editor

An image editing program with a graphical interface, written in C++ for CS213 (Assignment 1) at the Faculty of Computing & AI, Cairo University.

Course Instructor: Dr. Mohamed El-Ramly

## What it does

You load an image, pick a filter, see the result right away inside the program, and save it. The program has 18 filters, and it can also handle filters that change the size of the image, like Rotate, Resize, Crop, Frame and Skew.

## Filters

| # | Filter | # | Filter |
|---|---|---|---|
| 1 | Grayscale | 10 | Detect Image Edges |
| 2 | Black and White | 11 | Crop Image |
| 3 | Invert Image | 12 | Blur |
| 4 | Frame | 13 | Sunlight |
| 5 | Flip (Horizontal/Vertical) | 14 | Old TV |
| 6 | Rotate Image | 15 | Purple |
| 7 | Darken and Lighten | 16 | Samurai Red |
| 8 | Resize Image | 17 | Skew Image |
| 9 | Merge | 18 | Oil Painting |

## How to run

1. Clone the repository: `git clone <repository-url>`
2. Open the project in CLion (or any C++ IDE).
3. Make sure `Image_Class.h` is in the project folder.
4. Build and run.
5. Load an image, choose a filter, then save the result.

## Who did what (GUI)

| Member | Part |
|---|---|
| Rana Amr Ismail | Main window and layout, integration |
| Fatma Mohamed Hassan | Load and save, file dialogs, integration |
| Menna Khaled Said | Filters panel and buttons, connecting buttons to the filters, testing |
| Menna Hossam Shahat | Showing the image and refreshing it after each filter, handling images that change size, testing |

When everyone finished her part, we put it all together and went through the GUI and all 18 filters as a team. The documentation, video and GitHub repository were done by all of us.

## Team

| Name | ID | Section |
|---|---|---|
| Rana Amr Ismail | 20250231 | S7, S8 |
| Fatma Mohamed Hassan | 20250464 | S15, S16 |
| Menna Khaled Said | 20250672 | S7, S8 |
| Menna Hossam Shahat | 20251433 | S37, S38 |

## Project Links

**Demo Video:**  
https://drive.google.com/file/d/1Qvjm43RlMcGwz9Cde9WN_UxEX2tesINT/view?usp=sharing

**Shared Documentation:**  
https://drive.google.com/file/d/1PM0ot1aD21gaIMATjdwKNKZcSBzx23pV/view?usp=drivesdk
