#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#define V 8
/* Location numbers */
enum
{
    MAIN_GATE,
    ADMIN_BLOCK,
    LIBRARY,
    ACADEMIC_BLOCK,
    CANTEEN,
    COMPUTER_LAB,
    HOSTEL,
    AUDITORIUM
};
/* Graph */
int graph[V][V] = {0};
/* Parent array for shortest path */
int parent[V];
/* Add an undirected edge */
void add_edge(int u, int v, int weight)
{
    graph[u][v] = weight;
    graph[v][u] = weight;
}
/* Print location name */
void print_location(int location)
{
    switch (location)
    {
    case MAIN_GATE:
        printf("MAIN GATE");
        break;

    case ADMIN_BLOCK:
        printf("ADMIN BLOCK");
        break;

    case LIBRARY:
        printf("LIBRARY");
        break;

    case ACADEMIC_BLOCK:
        printf("ACADEMIC BLOCK");
        break;

    case CANTEEN:
        printf("CANTEEN");
        break;

    case COMPUTER_LAB:
        printf("COMPUTER LAB");
        break;

    case HOSTEL:
        printf("HOSTEL");
        break;

    case AUDITORIUM:
        printf("AUDITORIUM");
        break;
    }
}
void generate_graphviz(int source, int destination)
{
    FILE *fp = fopen("campus.dot", "w");
    if (fp == NULL)
    {
        printf("\nERROR: campus.dot file create nahi ho payi!\n");
        return;
    }

    fprintf(fp, "graph Campus {\n");

    fprintf(fp, "    layout=neato;\n");
    fprintf(fp, "    overlap=false;\n");
    fprintf(fp, "    splines=true;\n");
    fprintf(fp, "    bgcolor=\"white\";\n\n");

    fprintf(fp,
            "    node [shape=box, style=\"rounded,filled\", "
            "fillcolor=\"lightgray\", fontname=\"Arial\"];\n\n");
    /* Print all edges */
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] != 0)
            {
                int highlight = 0;
                int current = destination;
                while (current != -1)
                {
                    if (parent[current] == i && current == j)
                    {
                        highlight = 1;
                        break;
                    }
                    if (parent[current] == j && current == i)
                    {
                        highlight = 1;
                        break;
                    }
                    current = parent[current];
                }

                fprintf(fp, "    \"");

                /* First location */
                switch (i)
                {
                case MAIN_GATE:
                    fprintf(fp, "MAIN GATE");
                    break;
                case ADMIN_BLOCK:
                    fprintf(fp, "ADMIN BLOCK");
                    break;
                case LIBRARY:
                    fprintf(fp, "LIBRARY");
                    break;
                case ACADEMIC_BLOCK:
                    fprintf(fp, "ACADEMIC BLOCK");
                    break;
                case CANTEEN:
                    fprintf(fp, "CANTEEN");
                    break;
                case COMPUTER_LAB:
                    fprintf(fp, "COMPUTER LAB");
                    break;
                case HOSTEL:
                    fprintf(fp, "HOSTEL");
                    break;
                case AUDITORIUM:
                    fprintf(fp, "AUDITORIUM");
                    break;
                }

                fprintf(fp, "\" -- \"");

                /* Second location */
                switch (j)
                {
                case MAIN_GATE:
                    fprintf(fp, "MAIN GATE");
                    break;
                case ADMIN_BLOCK:
                    fprintf(fp, "ADMIN BLOCK");
                    break;
                case LIBRARY:
                    fprintf(fp, "LIBRARY");
                    break;
                case ACADEMIC_BLOCK:
                    fprintf(fp, "ACADEMIC BLOCK");
                    break;
                case CANTEEN:
                    fprintf(fp, "CANTEEN");
                    break;
                case COMPUTER_LAB:
                    fprintf(fp, "COMPUTER LAB");
                    break;
                case HOSTEL:
                    fprintf(fp, "HOSTEL");
                    break;
                case AUDITORIUM:
                    fprintf(fp, "AUDITORIUM");
                    break;
                }

                fprintf(fp, "\" [label=\"%d\"", graph[i][j]);

                /* Highlight shortest path */
                if (highlight)
                {
                    fprintf(fp,
                            ", color=\"red\", "
                            "penwidth=4");
                }
                else
                {
                    fprintf(fp,
                            ", color=\"black\", "
                            "penwidth=1.5");
                }

                fprintf(fp, "];\n");
            }
        }
    }

    /* Highlight source */
    fprintf(fp, "    \"");

    switch (source)
    {
    case MAIN_GATE:
        fprintf(fp, "MAIN GATE");
        break;
    case ADMIN_BLOCK:
        fprintf(fp, "ADMIN BLOCK");
        break;
    case LIBRARY:
        fprintf(fp, "LIBRARY");
        break;
    case ACADEMIC_BLOCK:
        fprintf(fp, "ACADEMIC BLOCK");
        break;
    case CANTEEN:
        fprintf(fp, "CANTEEN");
        break;
    case COMPUTER_LAB:
        fprintf(fp, "COMPUTER LAB");
        break;
    case HOSTEL:
        fprintf(fp, "HOSTEL");
        break;
    case AUDITORIUM:
        fprintf(fp, "AUDITORIUM");
        break;
    }

    fprintf(fp, "\" [color=\"green\", penwidth=4];\n");

    /* Highlight destination */
    fprintf(fp, "    \"");

    switch (destination)
    {
    case MAIN_GATE:
        fprintf(fp, "MAIN GATE");
        break;
    case ADMIN_BLOCK:
        fprintf(fp, "ADMIN BLOCK");
        break;
    case LIBRARY:
        fprintf(fp, "LIBRARY");
        break;
    case ACADEMIC_BLOCK:
        fprintf(fp, "ACADEMIC BLOCK");
        break;
    case CANTEEN:
        fprintf(fp, "CANTEEN");
        break;
    case COMPUTER_LAB:
        fprintf(fp, "COMPUTER LAB");
        break;
    case HOSTEL:
        fprintf(fp, "HOSTEL");
        break;
    case AUDITORIUM:
        fprintf(fp, "AUDITORIUM");
        break;
    }
    fprintf(fp, "\" [color=\"blue\", penwidth=4];\n");
    fprintf(fp, "}\n");
    fclose(fp);

    printf("\n========================================\n");
    printf("DOT FILE CREATED SUCCESSFULLY!\n");
    printf("File: campus.dot\n");
    printf("========================================\n");
}

/* Convert location name into its number */
int get_location(char name[], int n)
{
    for(int i=0 ; i<n ; i++){
        name[i]=toupper(name[i]);
    }
    if (strcmp(name, "MAIN GATE") == 0)
        return MAIN_GATE;

    if (strcmp(name, "ADMIN BLOCK") == 0)
        return ADMIN_BLOCK;

    if (strcmp(name, "LIBRARY") == 0)
        return LIBRARY;

    if (strcmp(name, "ACADEMIC BLOCK") == 0)
        return ACADEMIC_BLOCK;

    if (strcmp(name, "CANTEEN") == 0)
        return CANTEEN;

    if (strcmp(name, "COMPUTER LAB") == 0)
        return COMPUTER_LAB;

    if (strcmp(name, "HOSTEL") == 0)
        return HOSTEL;

    if (strcmp(name, "AUDITORIUM") == 0)
        return AUDITORIUM;

    return -1;
}

/* Find unvisited vertex with minimum distance */
int minimum_distance(int dist[], int visited[])
{
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

/* Dijkstra's algorithm */
int dijkstra(int source, int destination)
{
    int dist[V];
    int visited[V];

    /* Initialization */
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    /* Main Dijkstra loop */
    for (int i = 0; i < V; i++)
    {
        int u = minimum_distance(dist, visited);
        if (u == -1)
            break;
        visited[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (visited[v] == 0 &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[v] > dist[u] + graph[u][v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    return dist[destination];
}

/* Main function */
int main(void)
{
    char source_name[50];
    char destination_name[50];

    int source;
    int destination;
    int distance;

    int path[V];
    int count = 0;
    int current;

    /* ---------------- GRAPH ---------------- */

    add_edge(MAIN_GATE, ADMIN_BLOCK, 100);
    add_edge(MAIN_GATE, LIBRARY, 180);
    add_edge(MAIN_GATE, AUDITORIUM, 300);

    add_edge(ADMIN_BLOCK, LIBRARY, 80);
    add_edge(ADMIN_BLOCK, ACADEMIC_BLOCK, 120);

    add_edge(LIBRARY, ACADEMIC_BLOCK, 70);
    add_edge(LIBRARY, CANTEEN, 90);

    add_edge(ACADEMIC_BLOCK, CANTEEN, 60);
    add_edge(ACADEMIC_BLOCK, COMPUTER_LAB, 100);

    add_edge(CANTEEN, COMPUTER_LAB, 80);
    add_edge(CANTEEN, HOSTEL, 150);

    add_edge(COMPUTER_LAB, HOSTEL, 120);
    add_edge(COMPUTER_LAB, AUDITORIUM, 140);

    add_edge(HOSTEL, AUDITORIUM, 100);

    /* ---------------- HEADER ---------------- */

    printf("========================================\n");
    printf("       COLLEGE CAMPUS NAVIGATION\n");
    printf("========================================\n\n");

    printf("Available locations:\n");
    printf("MAIN GATE\n");
    printf("ADMIN BLOCK\n");
    printf("LIBRARY\n");
    printf("ACADEMIC BLOCK\n");
    printf("CANTEEN\n");
    printf("COMPUTER LAB\n");
    printf("HOSTEL\n");
    printf("AUDITORIUM\n\n");

    /* ---------------- SOURCE ---------------- */

    printf("ENTER YOUR CURRENT LOCATION: ");

    fgets(source_name, sizeof(source_name), stdin);

    source_name[strcspn(source_name, "\n")] = '\0';

    source = get_location(source_name,50);

    if (source == -1)
    {
        printf("\nINVALID CURRENT LOCATION!\n");
        return 0;
    }

    /* ---------------- DESTINATION ---------------- */

    printf("ENTER YOUR DESTINATION: ");

    fgets(destination_name, sizeof(destination_name), stdin);

    destination_name[strcspn(destination_name, "\n")] = '\0';

    destination = get_location(destination_name,50);

    if (destination == -1)
    {
        printf("\nINVALID DESTINATION!\n");
        return 0;
    }

    /* ---------------- DIJKSTRA ---------------- */

    distance = dijkstra(source, destination);

    if (distance == INT_MAX)
    {
        printf("\nNO ROUTE AVAILABLE.\n");
        return 0;
    }

    /* ---------------- GENERATE GRAPH ---------------- */

    generate_graphviz(source, destination);

    /* ---------------- GRAPHVIZ ---------------- */

    printf("\nGenerating campus graph using Graphviz...\n");

    /*
       Generate PNG from DOT file
    */
    int result = system("dot -Tpng -Gdpi=180 campus.dot -o campus.png");

    if (result != 0)
    {
        printf("\n========================================\n");
        printf("GRAPHVIZ ERROR!\n");
        printf("PNG file generate nahi hui.\n");
        printf("========================================\n");

        printf("\nDOT file campus.dot ban chuki hai.\n");
        printf("Usko manually Graphviz se open kar sakte ho.\n");
    }
    else
    {
        printf("\n========================================\n");
        printf("GRAPH GENERATED SUCCESSFULLY!\n");
        printf("File: campus.png\n");
        printf("========================================\n");

        /*
           Open current folder in Windows Explorer
           and select campus.png
        */
        system("start \"\" /max \"campus.png\"");
    }

    /* ---------------- FIND PATH ---------------- */

    current = destination;

    while (current != -1 && count < V)
    {
        path[count] = current;
        count++;

        current = parent[current];
    }

    /* ---------------- OUTPUT ---------------- */

    printf("\n========================================\n");
    printf("             RESULT\n");
    printf("========================================\n");

    printf("\nShortest Distance: %d meters\n", distance);

    printf("Shortest Route: ");

    for (int i = count - 1; i >= 0; i--)
    {
        print_location(path[i]);

        if (i != 0)
            printf(" -> ");
    }

    printf("\n\n========================================\n");

    return 0;
}