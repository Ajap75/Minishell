# Minishell
As beautiful as a shell

Thanks to Minishell, you’ll be able to travel through time and come back to problems
people faced when Windows didn’t exist...

Shell should :

Display a prompt when waiting for a new command.

Have a working history.

Search and launch the right executable (based on the PATH variable or using a relative or an absolute path).

1 seule variable globale uniquement pour la reception de signal.

Ne pas interpréter les guillemets non fermés ou les caractères spéciaux qui ne sont pas requis par le sujet  \ (barre oblique inverse) & ; (point-virgule).
Gerer les guillemets simples (devrait empecher le shell d'interpreter les metacaracteres dans le sequence citee).
Gerer les guillemets doubles (devrait empecher le shell d'interpreter les metacaracteres dans la sequence apart $ (signe dollar).

Implementer les redirections :

< redirige l'entree
> redirige la sortie
<< doit recevoir un delimiteur, puis lire l'entree jusqua ce qu'une ligne contenant le dilimiteur apparaisse. (mise a jour de l'historique pas necessaire)
>> doit rediriger la sortie en mode ajout. (join)

Implementer les pipelines (caractere |)

Gerer les variables d'environnement ($ suivi d'une sequence de caracteres) qui doivent se developper jusqu'a leur valeur.

Gerer $? qui devrait s'etendre au statut de storie du pipeline de premier plan execute le plus recemment..

Gerer ctrl-C ctrl-D et ctrl-\ qui doivent se comporter comme dans bash.

En mode interactif :
ctrl-C affiche une nouvelle invite sur une nouvelle ligne
ctrl-D quitte le shell
ctrl-\ ne fait rien

Implementer :

echo avec l'option -n
cd avec seulement un chemin relatif ou absolu
pwd sans options
export sans options
unset sans options
env sans options ou arguments
exit sans options

The readline() function cause leak memory, ne pas gerer.

BONUS PART :
Implementer && et || avec des parentheses pour les priorites.
Implementer * dans le repertoire actuel seulement.





Les cas tricky :


