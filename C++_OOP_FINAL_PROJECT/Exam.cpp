#include <iostream> // Include the iostream library for input/output operations
using namespace std; // Use the standard namespace

const int MAX_VERTICES = 100; // Define the maximum number of vertices in the graph

// Structure to represent an edge in the graph
struct Edge {
    int to; // Destination vertex ID
    float weight; // Weight of the edge
};

// Structure to represent a vertex in the graph
struct Vertex {
    int id; // Vertex ID
    Edge edges[MAX_VERTICES]; // Array of edges connected to this vertex
    int edgeCount; // Number of edges connected to this vertex
};

// Structure to represent the graph
struct Graph {
    Vertex vertices[MAX_VERTICES]; // Array of vertices in the graph
    int vertexCount; // Number of vertices in the graph
    bool isDirected; // Flag to indicate if the graph is directed or undirected
};

// Function to initialize the graph
void initGraph(Graph &g, bool directed) {
    g.vertexCount = 0; // Set the initial vertex count to 0
    g.isDirected = directed; // Set the directed flag based on the input
}

// Function to find the index of a vertex by its ID
int findVertexIndex(Graph &g, int id) {
    for (int i = 0; i < g.vertexCount; i++) { // Loop through all vertices
        if (g.vertices[i].id == id) // Check if the current vertex ID matches the given ID
            return i; // Return the index if found
    }
    return -1; // Return -1 if the vertex is not found
}

// Function to add a vertex to the graph
void addVertex(Graph &g, int id) {
    if (g.vertexCount >= MAX_VERTICES) { // Check if the maximum vertex limit is reached
        cout << "Vertex limit reached.\n"; // Print an error message
        return; // Exit the function
    }
    if (findVertexIndex(g, id) != -1) { // Check if the vertex already exists
        cout << "Vertex already exists.\n"; // Print an error message
        return; // Exit the function
    }
    g.vertices[g.vertexCount].id = id; // Assign the ID to the new vertex
    g.vertices[g.vertexCount].edgeCount = 0; // Initialize the edge count to 0
    g.vertexCount++; // Increment the vertex count
    cout << "Vertex " << id << " added.\n"; // Print a success message
}

// Function to add an edge to the graph
void addEdge(Graph &g, int from, int to, float weight) {
    int fromIndex = findVertexIndex(g, from); // Find the index of the source vertex
    int toIndex = findVertexIndex(g, to); // Find the index of the destination vertex

    if (fromIndex == -1 || toIndex == -1) { // Check if one or both vertices are not found
        cout << "One or both vertices not found.\n"; // Print an error message
        return; // Exit the function
    }

    Vertex &v1 = g.vertices[fromIndex]; // Get a reference to the source vertex
    v1.edges[v1.edgeCount].to = to; // Add the destination vertex ID to the edge
    v1.edges[v1.edgeCount].weight = weight; // Add the weight to the edge
    v1.edgeCount++; // Increment the edge count for the source vertex

    if (!g.isDirected) { // If the graph is undirected
        Vertex &v2 = g.vertices[toIndex]; // Get a reference to the destination vertex
        v2.edges[v2.edgeCount].to = from; // Add the source vertex ID to the edge
        v2.edges[v2.edgeCount].weight = weight; // Add the weight to the edge
        v2.edgeCount++; // Increment the edge count for the destination vertex
    }

    cout << "Edge added.\n"; // Print a success message
}

// Function to remove a vertex from the graph
void removeVertex(Graph &g, int id) {
    int index = findVertexIndex(g, id); // Find the index of the vertex to remove
    if (index == -1) { // Check if the vertex is not found
        cout << "Vertex not found.\n"; // Print an error message
        return; // Exit the function
    }

    for (int i = index; i < g.vertexCount - 1; i++) { // Shift all vertices after the removed vertex
        g.vertices[i] = g.vertices[i + 1]; // Copy the next vertex to the current position
    }
    g.vertexCount--; // Decrement the vertex count

    for (int i = 0; i < g.vertexCount; i++) { // Loop through all remaining vertices
        Vertex &v = g.vertices[i]; // Get a reference to the current vertex
        int newCount = 0; // Initialize a new edge count
        for (int j = 0; j < v.edgeCount; j++) { // Loop through all edges of the current vertex
            if (v.edges[j].to != id) { // Check if the edge does not point to the removed vertex
                v.edges[newCount++] = v.edges[j]; // Keep the edge and increment the new count
            }
        }
        v.edgeCount = newCount; // Update the edge count for the current vertex
    }

    cout << "Vertex " << id << " removed.\n"; // Print a success message
}

// Function to display the graph
void displayGraph(Graph &g) {
    cout << "\n--- Graph ---\n"; // Print a header
    for (int i = 0; i < g.vertexCount; i++) { // Loop through all vertices
        Vertex &v = g.vertices[i]; // Get a reference to the current vertex
        cout << "Vertex " << v.id << ": "; // Print the vertex ID
        for (int j = 0; j < v.edgeCount; j++) { // Loop through all edges of the current vertex
            cout << "-> " << v.edges[j].to << " (w:" << v.edges[j].weight << ") "; // Print the edge details
        }
        cout << endl; // Print a newline
    }
}

// Main function
int main() {
    Graph g; // Create a graph object
    int choice; // Variable to store the user's menu choice
    bool directed; // Variable to store the graph type (directed or undirected)
    int id, from, to; // Variables to store vertex IDs
    float weight; // Variable to store the edge weight

    cout << "Choose Graph Type:\n"; // Prompt the user to choose the graph type
    cout << "1. Directed\n"; // Option for directed graph
    cout << "2. Undirected\n"; // Option for undirected graph
    cout << "Enter choice: "; // Prompt for input
    cin >> choice; // Read the user's choice
    directed = (choice == 1); // Set the directed flag based on the user's choice

    initGraph(g, directed); // Initialize the graph

    do {
        cout << "\n===== MENU =====\n"; // Print the menu
        cout << "1. Add Vertex\n"; // Option to add a vertex
        cout << "2. Add Edge\n"; // Option to add an edge
        cout << "3. Remove Vertex\n"; // Option to remove a vertex
        cout << "4. Display Graph\n"; // Option to display the graph
        cout << "5. Exit\n"; // Option to exit the program
        cout << "Enter choice: "; // Prompt for input
        cin >> choice; // Read the user's choice

        switch (choice) { // Handle the user's choice
            case 1: // Add a vertex
                cout << "Enter vertex ID: "; // Prompt for vertex ID
                cin >> id; // Read the vertex ID
                addVertex(g, id); // Add the vertex to the graph
                break;
            case 2: // Add an edge
                cout << "Enter from vertex ID: "; // Prompt for source vertex ID
                cin >> from; // Read the source vertex ID
                cout << "Enter to vertex ID: "; // Prompt for destination vertex ID
                cin >> to; // Read the destination vertex ID
                cout << "Enter weight: "; // Prompt for edge weight
                cin >> weight; // Read the edge weight
                addEdge(g, from, to, weight); // Add the edge to the graph
                break;
            case 3: // Remove a vertex
                cout << "Enter vertex ID to remove: "; // Prompt for vertex ID
                cin >> id; // Read the vertex ID
                removeVertex(g, id); // Remove the vertex from the graph
                break;
            case 4: // Display the graph
                displayGraph(g); // Call the function to display the graph
                break;
            case 5: // Exit the program
                cout << "Exiting program.\n"; // Print a goodbye message
                break;
            default: // Handle invalid input
                cout << "Invalid choice.\n"; // Print an error message
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0; // Return 0 to indicate successful execution
}
