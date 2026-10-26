int __thiscall sub_4276F0(_DWORD *this)
{
  int result; // eax
  int v3; // edx
  int v4; // eax
  double v5; // st7
  int v6; // edx
  int v7; // ecx
  double v8; // st7
  char *v9; // eax
  int v10; // edi
  double v11; // st7
  double v12; // st7
  bool v13; // [esp+Fh] [ebp-5h]
  float v14; // [esp+10h] [ebp-4h]
  int v15; // [esp+10h] [ebp-4h]

  result = sub_4EED40(this[20]);
  if ( !(_BYTE)result )
  {
    v3 = this[6124];
    *((_BYTE *)this + 24492) = 0;
    v4 = this[6146];
    if ( v4 + 1 > v3 )
    {
      if ( dword_75CBB0 == 7 )
      {
        if ( dword_75CBB4 != 8 )
          *((_BYTE *)this + 24492) = 1;
        v5 = (double)(dword_7D74B8 - this[5212]) + 1.5;
      }
      else
      {
        v5 = (double)(int)this[4 * v4 + 6126] - (double)(int)this[5212];
      }
    }
    else
    {
      v5 = (double)(this[4 * v4 + 6130] - this[5212]) + 1.5;
    }
    v14 = v5;
    if ( (*((_BYTE *)this + 18910)
       || *((float *)this + 4945) != 0.0
       || *((float *)this + 4946) != 0.0
       || *((float *)this + 4947) != 0.0)
      && dword_75CBB0 == 7 )
    {
      sub_51C180(this + 21);
      v6 = this[5212];
      v7 = 4 * this[6146];
      *((_BYTE *)this + 24492) = 0;
      this[v7 + 6126] = v6;
      this[4 * this[6146] + 6129] = 8;
    }
    if ( sub_4280C0(this) || dword_75CBB0 != 7 )
    {
      *((float *)this + 6057) = *((float *)this + 5963) + 180.0;
      if ( dword_75CBB0 == 7 )
      {
        this[6006] = 3;
        sub_4EEC20(0);
        sub_4EEC50(0);
        sub_4EECE0(0);
        sub_4DCC00(1, 0);
      }
    }
    if ( v14 >= 3.0 )
      v8 = v14;
    else
      v8 = 3.0;
    *(float *)&this[4 * this[6146] + 6127] = v8 * *((float *)this + 6148);
    sub_4C1710(*(float *)&this[4 * this[6146] + 6127]);
    v9 = (char *)sub_51E210(this + 21);
    v15 = sub_4BFFC0(v9);
    if ( flt_7DAB04 >= 0.25 )
      v10 = 5;
    else
      v10 = this[6125];
    if ( *(_BYTE *)this )
      v10 = 5;
    *(_BYTE *)this = 0;
    if ( *((float *)this + 4612) <= (double)*((float *)this + 4488) )
      v11 = *((float *)this + 4612);
    else
      v11 = *((float *)this + 4488);
    v13 = v11 < 0.94;
    if ( *((float *)this + 4674) <= (double)*((float *)this + 4550) )
      v12 = *((float *)this + 4674);
    else
      v12 = *((float *)this + 4550);
    if ( v10 == 5 )
    {
      if ( this[4219] )
        goto LABEL_39;
    }
    else if ( v10 != 7 || !this[4219] )
    {
LABEL_39:
      if ( v10 == v15 )
      {
        if ( !v13 )
        {
          if ( v12 < 0.94 )
            return sub_4C1750(2);
          else
            return sub_4C1750(0);
        }
        if ( v12 >= 0.94 )
          return sub_4C1750(1);
      }
      return sub_4C1750(3);
    }
    sub_4C0C10(4);
    goto LABEL_39;
  }
  return result;
}
