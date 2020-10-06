#    `C++` code generation - bootstrap strategy

Code generation
===============

In our journey as a programmer, we can find ourselves in a situation
where we have a very repetitive operation. Sometimes we have data that
has to be translated into code. Usually, the solution is to generate the
boilerplate code using a tool; sometimes, we use to write a small script
that does the job for us.

Bootstrap
---------

Probably you have heard of the bootstrap paradox. Where an object or
piece of information (a compiler in our case) is sent back in time and
became trapped in a time loop. In this case, bootstrapping is about
building a compiler using tools smaller than itself, as opposed to
building a compiler using an already made version of itself.

Example: Pretty printer for `C++` code
======================================

This project present a very simple pretty-printer for `C++` code. The
idea is to avoid to build a full *Abstract Syntax Tree* with the
*emitter*, *parser*, and all required machinery. This project presents a
very simple pretty-printer for `C++` code. The idea is to avoid to build
a full *Abstract Syntax Tree* with the *emitter*, *parser*, and all
required machinery. In this case, we will use a bootstrap strategy to
build an [enumeration](include/generaattori/cpp/tokens.h) of all reserved words and operator of the `C++`
language and the printing method for each of them.

Data preparation
----------------

The first task that we performed is collecting the full list of all
*reserved words* and *operators* of the Language. We compile them in
`TSV` [file](src/resources/cpp-tokens.tsv). We defined a name, lexem, and a category for each word. You
can take a look here.

Compilation Unit
----------------

See [cu.h](include/generaattori/cpp/cu.h) header file.

### Identifiers

Identifiers are the basic block of any programming language, apart from
the *operators* and *reserved words*. In this example, we will handle
local variables, public members, protected members, private members,
namespaces, and type names. We defined an enumeration for this purpose.
Then we create a simple class that contains the *lexem* and the category
of the identifier. Of course, we wrote the operators and required
constructors to be able to use them efficiently.

### Line information

Another critical point is source code tracking. The particular fact
about generated code is the source. The start a generated code is not
the code itself, it is the generator's code. Given that fact, when we
want to debug the code, we must prefer to follow the path in the code
generator rather than the generated one. For this particular purpose, we
carry the source file and line information using a straightforward class
container.

### Compilation Unit

The concept of a compilation unit is usually associated with a single
file that is processed by the compiler. In our implementation, we use an
output stream instance where we write all the code, and we define pretty
much all the language literal lexemes printing methods. Also, we handle
the concept of Scopes using coding blocks taking advantage of the
**RAII** design pattern. Using the capabilities of the language of
creating anonymous lambda functions that handle each own *Scope*, we
create a mechanism that helps the readability of the code.

### Helper Macros

We defined pre-processor macros that provide simplicity at the writing
code time. In particular for the moment of open and closing *Scopes*.

`TSV` to `C++` translation
--------------------------

The first step is simple, just parse the file and load all the rows in a
`struct`. After that, we initialise the compilation unit, and we start
writing the code. As any other header file, we define a guard, to avoid
that the code is included more than once, later some library Include and
the namespace declaration.

Then, we write the Enumeration as a declaration, and we traverse all the
entries loaded from the file and print the corresponding entries.
Analogously, we apply the same procedure for the categories.

The most complicated part here is the print method when we declare a
`template` method. We all know that `template`s in `C++` are detailed,
now imagine a code generation for the `template` method. But, as any
task, we start for the beginning, with the declaration, writing the
prototype of the function. In the body, we add a colossal `switch`
statement with all the entries of the file and the corresponding `case`,
we print the lexem character by character.

Finally, we define a lookup array for the corresponding category of each
*reserved word* based in their position.

Discussion
==========

As you may have noticed, we have previously generated the tokens header
file, before we have compiled the code and rendered it. This is the trap
in the time-travel loop. Of course, where were previous iterations of
this process, but they are not relevant to explain the concept of the
bootstrap strategy.

As you may have noticed, we have previously generated the tokens header
file, before we have compiled the code and rendered it. This is the trap
in the time travel loop. Of course, where were previous iterations of
this process, but they are not relevant to explain the concept of the
bootstrap strategy.