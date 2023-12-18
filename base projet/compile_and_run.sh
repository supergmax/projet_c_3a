
#!/bin/bash

# Compilation du fichier source C
gcc -o exec v2.1.c

# Vérification si la compilation a réussi
if [ $? -eq 0 ]; then
    echo "Compilation réussie. Exécutable 'exec' créé."
else
    echo "Erreur de compilation."
fi
