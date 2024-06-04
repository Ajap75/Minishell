# Minishell
As beautiful as a shell

Thanks to Minishell, you’ll be able to travel through time and come back to problems
people faced when Windows didn’t exist...

Consignes :

Afficher un prompt lorsque l'on attend une nouvelle commande.

Avoir un historiques des commandes

Recherchez et lancez le bon exécutable (en fonction de la variable PATH ou en utilisant un chemin relatif ou absolu).

1 seule variable globale uniquement pour la reception de signals.

Ne pas interpréter les guillemets non fermés ou les caractères spéciaux qui ne sont pas requis par le sujet  \ (barre oblique inverse) & ; (point-virgule).
Gerer les guillemets simples (devrait empecher le shell d'interpreter les metacaracteres dans le sequence citee).
Gerer les guillemets doubles (devrait empecher le shell d'interpreter les metacaracteres dans la sequence apart $ (signe dollar).

Implementer les redirections :

"<" redirige l'entree.

">" redirige la sortie.

"<<" doit recevoir un delimiteur, puis lire l'entree jusqua ce qu'une ligne contenant le dilimiteur apparaisse (mise a jour de l'historique pas necessaire).

">>" doit rediriger la sortie en mode ajout (join sur la sortie).

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


FONCTIONS AUTORISEES :

readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs


BONUS PART :

Implementer && et || avec des parentheses pour les priorites.
Implementer * dans le repertoire actuel seulement.


Les cas pieges lors de la correction :

Overflow sur le signal d'exit

Supression du dossier dans lequel on est ( pouvoir revenir du void avec cd ..)




