int __thiscall sub_4B8F00(_DWORD *this)
{
  char *v2; // eax
  _DWORD *v3; // ecx
  const char *v4; // eax
  const char *v5; // eax
  char *v6; // eax
  _BYTE v8[125]; // [esp+8h] [ebp-80h] BYREF
  __int16 v9; // [esp+85h] [ebp-3h]
  char v10; // [esp+87h] [ebp-1h]

  memset(v8, 0, sizeof(v8));
  v9 = 0;
  v10 = 0;
  v2 = sub_41D840(&byte_91CC38, "No Controller Detected");
  sub_630FE0(v8, v2, 127);
  v10 = 0;
  sub_409FB0(this + 13);
  switch ( this[69] )
  {
    case 1:
      sub_4D3CF0("KEYBOARD", -1);
      goto LABEL_3;
    case 2:
LABEL_3:
      v3 = &unk_B6A474;
      goto LABEL_6;
    case 3:
      v3 = &unk_B6A878;
      goto LABEL_6;
    case 4:
      v3 = &unk_B6AC7C;
LABEL_6:
      v4 = (const char *)sub_45DC60(v3);
      sub_48D650(v4, (int)v8);
      break;
    default:
      break;
  }
  v5 = (const char *)sub_4CFC00(0);
  v6 = sub_41D840(&byte_91CC38, v5);
  sub_615860(v6);
  return 0;
}
