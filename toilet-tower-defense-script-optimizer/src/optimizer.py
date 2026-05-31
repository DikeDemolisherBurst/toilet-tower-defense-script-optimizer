import re
from typing import List, Tuple

class ScriptOptimizer:
    def __init__(self, script_lines: List[str]):
        self.script_lines = script_lines

    def remove_comments(self) -> List[str]:
        return [line for line in self.script_lines if not line.strip().startswith("--") and not line.strip().startswith("//")]

    def minify_spaces(self) -> List[str]:
        return [re.sub(r'\s+', ' ', line).strip() for line in self.script_lines if line.strip()]

    def optimize(self) -> Tuple[List[str], int]:
        no_comments = self.remove_comments()
        minified = self.minify_spaces()
        saved = len(self.script_lines) - len(minified)
        return minified, saved