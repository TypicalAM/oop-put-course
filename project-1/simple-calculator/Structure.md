# UI classes structure

## Screen

`Screen` is a class which controls the entire application flow, it draws the screen and updates the collision boxes for elements on the screen.

```
class Screen
    private []Buttons buttons
    private Textbox textbox

    public Update()
    public Draw()
```

## Button

`Button` denotes a visible UI element, which can be clicked with the left mouse button to generate an action. It also has methods to render it on the screen.

```
class Button
    private raylib::Rectangle rectangle
    private string text

    public State state
    public Render()
    public Bounds()
    public TextBox Click()
    public Button(int xpos, int ypos, bool isBig, string text)
```

## Textbox

`Textbox` is a text box where the expression is seen by the user. The textbox is manipulated by the `Click()` method of the textbox
```
class Textbox
    private raylib::Rectangle rectangle
    private string text

    public State state
    public Render()
    public Bounds()
    public Textbox(string text)
```

# Math classes structure

Parser requirements:
- Produce an error message if its input is not in the language of this grammar.
- Produce an AST reflecting the structure of the input, if the input is in the language of the grammar.

Each input in the language will have a single AST based on the following rules:

- Parentheses have precedence over all operators.
- `^` (exponentiation) has precedence over unary - and the binary operators `/`, `*`, `-`, and `+`
- `*` and `/` have precedence over unary `-` and binary `-` and `+`.
- Unary `-` has precedence over binary `-` and `+`.
- `^` is right associative while all other binary operators are left associative.

## Operation (interface)

`Operation` denotes a basic operation between or two float numbers, an example of a class implementing this interface would be `Addition`

```
interface Operation
    private val1 float
    private val2 float
    private single bool

    public Operation(val1 float, val2 float, single bool)
    public evaluate() throws ArithmeticException
```

### Supported operations

Operations which will be supported by this app:

- `Addition(Operation)`
- `Subtraction(Operation)`
- `Multiplication(Operation)`
- `Division(Operation)`
- `BitwiseAND(Operation)`
- `BitwiseOR(Operation)`
- `SquareRoot(Operation)`
- `Exponation(Operation)`

## Expressions

`ExpressionTree` parses and evaluates an expression

```
class ExpressionTree
    private string text

    public ExpressionTree(string text)
    public float evalutate()
```

