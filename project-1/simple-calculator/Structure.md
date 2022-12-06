# Classes structure

## Screen

`Screen` is a class which controls the entire application flow, it draws the screen and updates the collision boxes for elements on the screen.

```
class Screen
    private []Buttons

    public update()
    public draw()
```

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

## Expression

`Expression` parses and evaluates an expression

```
class Expression
    private string text

    public Expression(string text)
    public float evalutate()
```

## Button

`Button` denotes a visible UI element, which can be clicked with the left mouse button to generate an action. It also has methods helping to render it on the screen.

```
interface Button
    private raylibRect bounds
    private string text
    public State state

    public Button(int xpos, int ypos, bool isBig, string text)
    public click()
    public render()
```

### Supported buttons

- `Division(Button)`
- `Multiplication(Button)`
- `Subtraction(Button)`
- `Addition(Button)`
- `Clear(Button)`
- `Reset(Button)`
- `SquareRoot(Operation)`
- `BitwiseOR(Button)`
- `Exponation(Operation)`
- `BitwiseAND(Button)`
- `Dot(Button)`
- `Result(Button)`
- `OpenParentheses(Button)`
- `CloseParentheses(Button)`

#### Supported digits

- `Zero(Digit)`
- `One(Digit)`
- `Two(Digit)`
- `Three(Digit)`
- `Four(Digit)`
- `Five(Digit)`
- `Six(Digit)`
- `Seven(Digit)`
- `Eight(Digit)`
- `Nine(Digit)`
