

Example:

[8c 18 a4 30 bc 48 d4 60 ec 78 04 90 1c a8 34 c0 4c d8 64 f0 7c 08 94 20 ac 38] operand 1
[fb ec dd ce bf b0 a1 92 83 74 65 56 47 38 29 1a 0b fc ed de cf c0 b1 a2 93 00] operand 2

Result:
[8c 18 a4 30 bc 48 a1 60 83 74 04 56 1c 38 29 1a 0b d8 64 de 7c 08 94 20 93 00]

falsch:
Grund: wsl wurde als länge der Mask result oder original mit result vertauscht

Step 1:
[8c 18 a4 30 bc 48 a1 60 83 74 04 56 1c 38 29 1a ff ff ff ff ff ff ff ff ff ff]