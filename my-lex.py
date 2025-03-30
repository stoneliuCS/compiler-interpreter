tokens = ("NAME", "NUMBER", "PLUS", "EQUALS", "TIMES", "MINUS", "DIVIDE", "STONE")

# Tokens

t_PLUS = r"\+"
t_NAME = r"[a-zA-Z_][a-zA-Z0-9_]*"
t_EQUALS = r"="
t_TIMES = r"\*"
t_MINUS = r"-"
t_DIVIDE = r"/"
t_STONE = r"\$STONE\$"


def t_NUMBER(t):
    r"\d+"
    try:
        t.value = int(t.value)
    except ValueError:
        print("Integer value too large %d", t.value)
        t.value = 0
    return t


# Ignored characters
t_ignore = " \t"


def t_newline(t):
    r"\n+"
    t.lexer.lineno += t.value.count("\n")


def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)


# Build the lexer
import ply.lex as lex

lexer = lex.lex()

# Parsing rules
precedence = (
    ("left", "PLUS"),
    ("left", "TIMES"),
    ("right", "USTONE"),
)
# dictionary of names
names = {}


def p_statement_assign(t):
    "statement : NAME EQUALS expression"
    names[t[1]] = t[3]
    print(names)


def p_expression_binop(t):
    """expression : expression PLUS expression
    | expression MINUS expression
    | expression TIMES expression
    | expression DIVIDE expression"""
    if t[2] == "+":
        t[0] = t[1] + t[3]
    elif t[2] == "*":
        t[0] = t[1] * t[3]


def p_expression_number(t):
    "expression : NUMBER"
    t[0] = t[1]

def p_expression_ustone(t):
    'expression : STONE expression %prec USTONE'
    t[0] = t[2]**5


def p_error(t):
    print("Syntax error at '%s'" % t.value)


import ply.yacc as yacc

parser = yacc.yacc()

s = "x = 2 + 2 + $STONE$2"
parser.parse(s)
