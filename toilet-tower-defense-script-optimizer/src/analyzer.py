from typing import List, Dict

class ScriptAnalyzer:
    def __init__(self, script_lines: List[str]):
        self.script_lines = script_lines

    def count_keywords(self) -> Dict[str, int]:
        keywords = ["spawn", "upgrade", "sell", "wave", "health", "cash"]
        counts = {kw: 0 for kw in keywords}
        for line in self.script_lines:
            for kw in keywords:
                if kw in line.lower():
                    counts[kw] += 1
        return counts

    def detect_inefficiencies(self) -> List[str]:
        warnings = []
        for i, line in enumerate(self.script_lines):
            if "while true" in line.lower() and "wait" not in line.lower():
                warnings.append(f"Line {i+1}: Infinite loop without wait - may freeze game")
            if "for" in line.lower() and "ipairs" in line.lower() and "wait" not in line.lower():
                warnings.append(f"Line {i+1}: Loop over table without yield - possible lag")
        return warnings