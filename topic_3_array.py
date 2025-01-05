class AppointmentArray:
    def __init__(self, size):
        self.array = [None] * size
        self.size = size

    def add_appointment(self, index, data):
        if 0 <= index < self.size:
            self.array[index] = data
        else:
            raise IndexError("Index out of bounds")

    def display(self):
        for i, item in enumerate(self.array):
            print(f"Slot {i}: {item}")

# Example Usage
appointments = AppointmentArray(5)
appointments.add_appointment(0, "Patient A")
appointments.add_appointment(2, "Patient C")
print("Array of Appointments:")
appointments.display()
