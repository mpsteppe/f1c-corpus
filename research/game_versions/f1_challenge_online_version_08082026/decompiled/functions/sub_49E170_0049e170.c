int __thiscall sub_49E170(_DWORD *this)
{
  int result; // eax
  _BYTE v3[16]; // [esp+4h] [ebp-10h] BYREF

  result = this[3];
  if ( result )
  {
    result = this[5];
    if ( result )
    {
      if ( *(_DWORD *)(result + 84) )
      {
        sub_58815F(v3, "%c", dword_7CE6AC + 33);
        sub_553070(v3, 0, 11, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE7CC + 36);
        sub_553070(v3, 42, 11, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE718 + 39);
        sub_553070(v3, 84, 11, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE7F0 + 42);
        sub_553070(v3, 126, 11, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE760 + 45);
        sub_553070(v3, 168, 11, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE784 + 48);
        sub_553070(v3, 210, 11, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE8A4 + 62);
        sub_553070(v3, 20, 65, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE6F4 + 52);
        sub_553070(v3, 62, 65, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE73C + 55);
        sub_553070(v3, 104, 65, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE7A8 + 58);
        sub_553070(v3, 146, 65, *(_DWORD *)(this[5] + 84));
        sub_58815F(v3, "%c", dword_7CE850 + 60);
        return sub_553070(v3, 188, 65, *(_DWORD *)(this[5] + 84));
      }
    }
  }
  return result;
}
