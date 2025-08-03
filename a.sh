#!/bin/bash

# --- Configuration ---
SOURCE_DIR="scaled_128x128" # Directory containing your extracted frames
FRAME_WIDTH=32                           # Width of a single frame
FRAME_HEIGHT=32                          # Height of a single frame
GRID_ROWS=8                              # Number of rows in your grid
GRID_COLS=8                              # Number of columns in your grid

echo "Starting renaming and deletion operations in '$SOURCE_DIR'..."

# Loop through each row and column as per the original extraction
for ((row_idx = 0; row_idx < GRID_ROWS; row_idx++)); do
    for ((col_idx = 0; col_idx < GRID_COLS; col_idx++)); do

        OLD_FILENAME="${SOURCE_DIR}/frame_r${row_idx}_c${col_idx}.xpm"

        # Check if the file exists before attempting to process it
        if [ ! -f "$OLD_FILENAME" ]; then
            echo "Warning: File '$OLD_FILENAME' not found. Skipping."
            continue
        fi

        case $row_idx in
            0) # Row 0: Idle
                NEW_FILENAME="${SOURCE_DIR}/idle_c${col_idx}.xpm"
                echo "Renaming '$OLD_FILENAME' to '$NEW_FILENAME'"
                mv "$OLD_FILENAME" "$NEW_FILENAME"
                ;;
            2|5) # Rows 2 and 5: Delete
                echo "Deleting '$OLD_FILENAME' (Row ${row_idx})"
                rm "$OLD_FILENAME"
                ;;
            3) # Row 3: Moving Right
                # Appending _r3 to keep source row explicit for "moving_right"
                NEW_FILENAME="${SOURCE_DIR}/moving_right_r3_c${col_idx}.xpm"
                echo "Renaming '$OLD_FILENAME' to '$NEW_FILENAME'"
                mv "$OLD_FILENAME" "$NEW_FILENAME"
                ;;
            4) # Row 4: Moving Right
                # Appending _r4 to keep source row explicit for "moving_right"
                NEW_FILENAME="${SOURCE_DIR}/moving_right_r4_c${col_idx}.xpm"
                echo "Renaming '$OLD_FILENAME' to '$NEW_FILENAME'"
                mv "$OLD_FILENAME" "$NEW_FILENAME"
                ;;
            6) # Row 6: Hit
                NEW_FILENAME="${SOURCE_DIR}/hit_c${col_idx}.xpm"
                echo "Renaming '$OLD_FILENAME' to '$NEW_FILENAME'"
                mv "$OLD_FILENAME" "$NEW_FILENAME"
                ;;
            7) # Row 7: Death
                NEW_FILENAME="${SOURCE_DIR}/death_c${col_idx}.xpm"
                echo "Renaming '$OLD_FILENAME' to '$NEW_FILENAME'"
                mv "$OLD_FILENAME" "$NEW_FILENAME"
                ;;
            *) # Other rows (if any, not specified in your rules)
                echo "No rule for row ${row_idx}. Keeping '$OLD_FILENAME' as is."
                ;;
        esac

    done # End of column loop
done # End of row loop

echo "--------------------------------------------------------"
echo "Renaming and deletion operations complete."
echo "Check the '$SOURCE_DIR' directory for updated files."
echo "--------------------------------------------------------"