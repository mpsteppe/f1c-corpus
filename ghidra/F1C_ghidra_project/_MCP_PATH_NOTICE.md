# MCP path notice

The preserved `.mcp.json` still references
`%USERPROFILE%\Desktop\ghidra-mcp`, which is nonexistent and predates the
canonical `tools\integrations\ghidra-mcp` location.

Owner decision Q15 requires notice-only handling. The configuration was not
corrected or executed. A future MCP setup task must review and explicitly
approve the live client configuration rather than trusting this stale file.
