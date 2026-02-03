# minishell - 42 School

Shell bash-like complet. Parsing commandes, pipes/redirections, builtins, heredoc, signals. **Compatible bash syntaxe + norme 42**. **Collab avec [gekid00](https://github.com/gekid00)**.

![Screenshot](screenshots/minishell.gif)

## Features
- **Parsing** : Quotes "'\"", $VAR expand, split espaces/tabs
- **Builtins** : echo, cd, pwd, export, unset, env, exit
- **Exec** : /bin/cmd, pipes multi ($|), redir < > >> <<
- **Heredoc** : `cat <<EOF` avec EOF multi-ligne
- **Signals** : Ctrl-C (reset), Ctrl-D (exit), Ctrl-\ (ignore)
- **Env** : $?, $USER, PATH/env vars

## Installation
```bash
make
# ou
make bonus  # Multi-commande heredoc
