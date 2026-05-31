import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))

from src.optimizer import ScriptOptimizer
from src.analyzer import ScriptAnalyzer

def test_remove_comments():
    lines = ["-- this is a comment", "spawn()", "// another comment"]
    opt = ScriptOptimizer(lines)
    result = opt.remove_comments()
    assert result == ["spawn()"]

def test_minify_spaces():
    lines = ["spawn   (   )  ", "  upgrade( ) "]
    opt = ScriptOptimizer(lines)
    result = opt.minify_spaces()
    assert result == ["spawn ( )", "upgrade( )"]

def test_optimize_saves_lines():
    lines = ["--comment", "spawn()", "  upgrade()  "]
    opt = ScriptOptimizer(lines)
    minified, saved = opt.optimize()
    assert saved == 1
    assert minified == ["spawn()", "upgrade()"]

def test_analyzer_keywords():
    lines = ["spawn toilet", "upgrade damage", "sell tower", "wave 5", "health low"]
    analyzer = ScriptAnalyzer(lines)
    counts = analyzer.count_keywords()
    assert counts["spawn"] == 1
    assert counts["wave"] == 1

def test_detect_inefficiencies():
    lines = ["while true do end", "for i, v in ipairs(t) do end"]
    analyzer = ScriptAnalyzer(lines)
    warnings = analyzer.detect_inefficiencies()
    assert len(warnings) == 2
    assert "Line 1" in warnings[0]