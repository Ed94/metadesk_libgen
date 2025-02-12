$misc = join-path $PSScriptRoot 'helpers/misc.ps1'
. $misc

$path_root = Get-ScriptRepoRoot

$url_metadesk  = 'https://github.com/Ed94/metadesk'
$path_metadesk = join-path $path_root 'metadesk'

clone-gitrepo $path_metadesk $url_metadesk
