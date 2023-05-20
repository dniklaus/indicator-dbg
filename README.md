# indicator-dbg

Debug and integration support for [Indicator](https://github.com/dniklaus/indicator) component using [DebugCLI](https://github.com/ERNICommunity/debug-cli) and [DbgTrace](https://github.com/ERNICommunity/dbg-trace).

This component provides a simple factory creating Indicator objects with a specified name and description.

# Integration
```C++
#include <Indicator.h>
#include <IndicatorFactory.h>

#include <DbgCliNode.h>
#include <DbgCliTopic.h>

// indicator implementation for built in LED
Indicator* led  = 0;

void setup()
{
  // create DebugCLI root node
  DbgCli_Node::AssignRootNode(new DbgCli_Topic(0, "dbg", "Debug CLI Root Node."));

  // indicator LED
  led = IndicatorFactory::createIndicator("led", "Built in LED.");
  led->assignAdapter(new MyBuiltinLedIndicatorAdapter());
}

```

# Dependencies

The Indicator Dbg component depends on the following components:

* [Indicator](https://github.com/dniklaus/indicator) - Iindicator providing a generic way to use output pins to indicate a binary state.
* [DebugCLI](https://github.com/ERNICommunity/debug-cli) - Command Line Interface for debugging and testing based on object oriented tree structure.
* [DbgTrace](https://github.com/ERNICommunity/dbg-trace) - Debug and Trace Log message system based on trace ports with adjustable levels.


# Debug CLI Commands
```
dbg                      Debug CLI root node
  tr                     Debug Trace Port config access
    <name>               Trace Port for the Indicator object (<name> defined during creation of the Indicator object)
      out                Trace Output config access for the current trace port
        get              Show the assigned Trace Output
        set <outName>    Set a particular Trace Output name
        list             Show all available Trace Output names (& currently selected)
      lvl                Trace Level config access for the current trace port
        get              Show the current trace level
        set <level>      Set a particular trace level
        list             Show all available trace levels (& currenntly selected)
  <name>                 Indicator node access (<name> defined during creation of the Indicator object)
    set [blink|on|off]   Set LED state (Usage: dbg led set [blink|on|off])
    pulse [<duration>]   Send a pulse on LED (Usage: dbg led pulse [pulseLengthMillis (>0)])
```
