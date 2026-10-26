int __userpurge sub_495C10@<eax>(const char *a1@<edi>, int ArgList, char *Buffer, size_t BufferCount)
{
  char *v4; // eax
  unsigned int v6; // kr00_4
  int v7; // edi
  const char *v8; // [esp+0h] [ebp-8h] BYREF

  v8 = a1;
  v6 = __readeflags();
  v7 = ~dword_16C6EEC ^ 0x6C9F3025;
  __writeeflags(v6);
  _InterlockedExchange((volatile __int32 *)&v8, v7);
  v4 = sub_41D840(&byte_91CC38, v8);
  switch ( ArgList )
  {
    case 1:
    case 21:
    case 31:
    case 41:
    case 51:
    case 61:
      v8 = "st";
      goto LABEL_5;
    case 2:
    case 22:
    case 32:
    case 42:
    case 52:
    case 62:
      v8 = "nd";
      goto LABEL_5;
    case 3:
    case 23:
    case 33:
    case 43:
    case 53:
    case 63:
      v8 = "rd";
LABEL_5:
      v4 = sub_41D840(&byte_91CC38, v8);
      break;
    default:
      return sub_41D810(Buffer, BufferCount, "%d%s", ArgList, v4);
  }
  return sub_41D810(Buffer, BufferCount, "%d%s", ArgList, v4);
}
