def bucket_sort(data, priority_map):
    buckets = {}
    for priority in priority_map.values():
        buckets[priority] = []
    
    for item, priority in data:
        buckets[priority].append(item)
    
    sorted_data = []
    for priority in sorted(buckets.keys()):
        sorted_data.extend(buckets[priority])
    
    return sorted_data

# Example Usage
priority_map = {"High": 1, "Medium": 2, "Low": 3}
data = [("Patient A", 1), ("Patient C", 3), ("Patient B", 2)]
print("Original Data:", data)
sorted_data = bucket_sort(data, priority_map)
print("Sorted Data:", sorted_data)
