void __thiscall sub_4DCEB0(int *this, int a2)
{
  int v3; // eax
  char Destination[29]; // [esp+8h] [ebp-A0h] BYREF
  __int16 v5; // [esp+25h] [ebp-83h]
  char v6; // [esp+27h] [ebp-81h]
  char Buffer[61]; // [esp+28h] [ebp-80h] BYREF
  __int16 v8; // [esp+65h] [ebp-43h]
  char v9; // [esp+67h] [ebp-41h]
  char v10[61]; // [esp+68h] [ebp-40h] BYREF
  __int16 v11; // [esp+A5h] [ebp-3h]
  char v12; // [esp+A7h] [ebp-1h]

  v3 = sub_4FA870(0);
  if ( a2 != this[82] && dword_7D74B8 - dword_6310D8[6326 * v3] > 0 )
  {
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x3Cu);
    v8 = 0;
    v9 = 0;
    v10[0] = byte_629120;
    memset(&v10[1], 0, 0x3Cu);
    v11 = 0;
    v12 = 0;
    if ( dword_75CBB4 > 3 )
      sub_405480(Buffer, 0x3Fu, aUnderCaution);
    else
      sub_405480(Buffer, 0x3Fu, aPaceLap);
    if ( a2 < 0 )
    {
      if ( (unsigned __int8)sub_4BBF20() )
      {
        if ( (unsigned __int8)sub_4F83B0(*this) )
          sub_405480(v10, 0x3Fu, "%s Stay Behind the Pace Car", Buffer);
        else
          sub_405480(v10, 0x3Fu, "%s Stay Behind the Pace Car On Inside Line", Buffer);
      }
    }
    else
    {
      Destination[0] = byte_629120;
      memset(&Destination[1], 0, 0x1Cu);
      v5 = 0;
      v6 = 0;
      sub_4EDE00(Destination, 31);
      if ( (unsigned __int8)sub_4F83B0(*this) )
        sub_405480(v10, 0x3Fu, "%s Stay Behind Car #%s", Buffer, Destination);
      else
        sub_405480(v10, 0x3Fu, "%s Stay Behind Car #%s On Inside Line", Buffer, Destination);
    }
    if ( dword_7D74B8 - dword_6310D8[6326 * sub_4FA870(0)] > 1
      && dword_75CBB4 != 8
      && (a2 >= 0 || (unsigned __int8)sub_4BBF20()) )
    {
      sub_45D100(&byte_764D68, (int)v10, 2, 16909060, 0);
      sub_41BB40(*this, a2);
    }
  }
  this[82] = a2;
}
