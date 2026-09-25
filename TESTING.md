# Line Editor Testing

## Test Cases

| Test Case | Expected Result |
|---|---|
| Insert line at beginning | Line is inserted successfully |
| Insert line at end | Line is inserted successfully |
| Delete existing line | Selected line is deleted |
| Delete non-existing line | Error message is displayed |
| Display empty document | Empty document message is displayed |
| Invalid line number | Error message is displayed |
| Save document | Document is saved to text file |
| Load document | Saved document is loaded successfully |

## Invalid Input Testing

The program is tested with:
- Invalid line numbers
- Empty document
- Deleting a non-existing line
- Inserting at the beginning
- Inserting at the end