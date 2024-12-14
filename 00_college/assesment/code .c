#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define TABLE_SIZE 1000  // Adjust based on expected URL count

typedef struct Node {
    char *url;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **table;
} HashTable;

// Hash function to generate index
unsigned int hash_function(const char *url) {
    unsigned int hash = 0;
    while (*url) {
        hash = (hash << 5) + *url++;
    }
    return hash % TABLE_SIZE;
}

// Create a new node for the URL or keyword
Node *create_node(const char *url) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->url = strdup(url);
    new_node->next = NULL;
    return new_node;
}

// Initialize hash table
HashTable *create_table() {
    HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));
    hash_table->table = (Node **)malloc(TABLE_SIZE * sizeof(Node *));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

// Insert URL or keyword into hash table
void insert_url(HashTable *hash_table, const char *url) {
    unsigned int index = hash_function(url);
    Node *new_node = create_node(url);

    // Insert at the beginning of the linked list (chaining)
    new_node->next = hash_table->table[index];
    hash_table->table[index] = new_node;
}

// Search for partial match in hash table
int search_partial_match(HashTable *hash_table, const char *input) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = hash_table->table[i];
        while (current) {
            if (strstr(current->url, input) != NULL) {
                return 1; // Partial match found in spam list
            }
            current = current->next;
        }
    }
    return 0; // No match found
}

// Add keywords entered in "creator mode" for tracking
void add_to_creator_mode(HashTable *hash_table, const char *input) {
    if (!search_partial_match(hash_table, input)) {
        printf("Adding '%s' to spam database as a suspicious keyword.\n", input);
        insert_url(hash_table, input);
    } else {
        printf("Keyword '%s' is already flagged as suspicious.\n", input);
    }
}

// Clean up memory by freeing hash table
void free_table(HashTable *hash_table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = hash_table->table[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp->url);
            free(temp);
        }
    }
    free(hash_table->table);
    free(hash_table);
}

// Function to add 50 known fake URLs to the hash table
void add_fake_urls(HashTable *hash_table) {
    const char *fake_urls[] = {
        "http://freemoneyoffers.com", "http://malicious-downloads.com", "http://fakebanklogin.com",
        "http://phishingsite.net", "http://dangerouslink.com", "http://clickhereforfree.com",
        "http://youvewonprize.com", "http://lottery-winner.com", "http://quickloanapproval.com",
        "http://spyware-infection.com", "http://get-rich-fast.com", "http://malwarealert.com",
        "http://freestuffnow.com", "http://amazingdeals.net", "http://cryptoscam.com",
        "http://instantcashnow.com", "http://onlinesecurityalert.com", "http://suspicioussite.org",
        "http://win-free-vacation.com", "http://luckydaywin.com", "http://bestinvestment.com",
        "http://greatopportunity.net", "http://instantjob.com", "http://secure-payment.net",
        "http://verifyaccountnow.com", "http://unlockdevice.com", "http://limitedoffer.com",
        "http://trialforfree.com", "http://freesamples.com", "http://workfromhomejob.com",
        "http://top10deals.net", "http://investmentplan.com", "http://pennystocks.com",
        "http://exclusiveoffer.com", "http://unclaimedreward.com", "http://freecomputerscan.com",
        "http://giftcardoffer.com", "http://lowcostmeds.com", "http://flights-deals.com",
        "http://instantrewards.com", "http://freecryptocurrency.com", "http://unsecuredloan.com",
        "http://cheapmedications.com", "http://holidaygiveaway.com", "http://mobileoffer.net",
        "http://unlockiphone.com", "http://realworkathome.com", "http://cheapinsurance.com",
        "http://datingoffers.com", "http://unclaimedprize.com"
    };
    int count = sizeof(fake_urls) / sizeof(fake_urls[0]);
    for (int i = 0; i < count; i++) {
        insert_url(hash_table, fake_urls[i]);
    }
}

// Function to handle creator mode
void creator_mode(HashTable *hash_table) {
    char input[256];
    printf("\n--- Creator Mode ---\n");
    printf("Enter a URL or keyword to check (or 'exit' to return to main menu): ");
    while (scanf("%255s", input) && strcmp(input, "exit") != 0) {
        if (search_partial_match(hash_table, input)) {
            printf("⚠️ Warning: The keyword or URL '%s' is flagged as suspicious!\n", input);
        } else {
            printf("The keyword or URL '%s' appears safe.\n", input);
            printf("Do you want to add '%s' to spam database as a suspicious keyword? (yes/no): ", input);
            char choice[4];
            scanf("%3s", choice);
            if (strcmp(choice, "yes") == 0) {
                add_to_creator_mode(hash_table, input);
            }
        }
        printf("\nEnter another URL or keyword to check (or 'exit' to return to main menu): ");
    }
}

// Function to handle normal mode
void normal_mode(HashTable *hash_table) {
    char input[256];
    printf("\n--- Normal Mode ---\n");
    printf("Enter a URL or keyword to check (or 'exit' to return to main menu): ");
    while (scanf("%255s", input) && strcmp(input, "exit") != 0) {
        if (search_partial_match(hash_table, input)) {
            printf("⚠️ Warning: The keyword or URL '%s' is flagged as suspicious!\n", input);
        } else {
            printf("The keyword or URL '%s' appears safe.\n", input);
        }
        printf("\nEnter another URL or keyword to check (or 'exit' to return to main menu): ");
    }
}

// Verify node position within the hash table
void node_position_verification(HashTable *hash_table) {
    char input[256];
    printf("\n--- Node Position Verification ---\n");
    printf("Enter a URL or keyword to check its position: ");
    scanf("%255s", input);

    unsigned int index = hash_function(input);
    Node *current = hash_table->table[index];
    int position = 0;
    int found = 0;

    while (current) {
        if (strcmp(current->url, input) == 0) {
            found = 1;
            printf("URL/Keyword '%s' found at index %u in position %d of the linked list.\n", input, index, position);
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        printf("URL/Keyword '%s' not found in the hash table.\n", input);
    }
}

// Display main menu and handle user selection
void main_menu(HashTable *hash_table) {
    int choice;
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Normal Mode\n");
        printf("2. Creator Mode\n");
        printf("3. Node Position Verification\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                normal_mode(hash_table);
                break;
            case 2:
                creator_mode(hash_table);
                break;
            case 3:
                node_position_verification(hash_table);
                break;
            case 4:
                printf("Exiting the program. Stay safe online!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    HashTable *hash_table = create_table();
    add_fake_urls(hash_table);

    // Start main menu
    main_menu(hash_table);

    // Free memory and exit
    free_table(hash_table);
    return 0;
}