void __thiscall sub_420A30(float *this)
{
  double v2; // st7
  int v3; // eax
  double v4; // st7
  int v5; // eax
  int v6; // eax
  double v7; // st7
  int v8; // ebp
  double v9; // st7
  double v10; // st6
  double v11; // st6
  double v12; // st6
  int v13; // eax
  double v14; // st6
  double v15; // st6
  double v16; // st7
  double v17; // st7
  int v18; // eax
  int v19; // edi
  long double v20; // st5
  float *v21; // eax
  long double v22; // st7
  double v23; // st7
  double v24; // st7
  float v25; // [esp+Ch] [ebp-1Ch]
  float v26; // [esp+Ch] [ebp-1Ch]
  float v27; // [esp+Ch] [ebp-1Ch]
  float v28; // [esp+Ch] [ebp-1Ch]
  float v29; // [esp+Ch] [ebp-1Ch]
  float v30; // [esp+10h] [ebp-18h]
  float v31; // [esp+10h] [ebp-18h]
  float v32; // [esp+14h] [ebp-14h]
  float v33; // [esp+14h] [ebp-14h]
  float v34; // [esp+18h] [ebp-10h]
  float v35; // [esp+18h] [ebp-10h]
  float v36; // [esp+1Ch] [ebp-Ch]
  float v37; // [esp+24h] [ebp-4h]

  if ( this[5119] > 5.0 )
  {
    if ( this[4061] >= (double)this[4124] )
      v2 = this[4124];
    else
      v2 = this[4061];
    if ( v2 < 0.5 )
      v2 = 0.5;
    this[5115] = v2 * this[5115];
  }
  v3 = *((_DWORD *)this + 5156);
  v34 = 0.050000001;
  v32 = 0.050000001;
  if ( v3 == -1 )
    v34 = 0.07;
  if ( v3 == 1 )
    v32 = 0.07;
  if ( *((_DWORD *)this + 5129) != 2139095039 )
  {
    v4 = this[5129];
    this[5092] = this[5129];
    this[5095] = v4;
  }
  v30 = this[5095];
  if ( *((_DWORD *)this + 5129) != 2139095039 )
  {
    if ( (unsigned __int8)sub_54F230(*(_DWORD *)this) )
    {
      v5 = *((_DWORD *)this + 5220);
      if ( v5 < 1 )
        v5 = 1;
      *((_DWORD *)this + 5220) = v5;
    }
    else
    {
      v6 = *((_DWORD *)this + 5221);
      if ( v6 < 1 )
        v6 = 1;
      *((_DWORD *)this + 5221) = v6;
    }
  }
  if ( *((_DWORD *)this + 5220) )
    this[5102] = this[5102] + 3.5;
  if ( *((_DWORD *)this + 5221) )
    this[5103] = this[5103] - 3.5;
  if ( this[5102] > (double)this[5103] )
  {
    v7 = (this[5102] + this[5103]) * 0.5;
    this[5102] = v7;
    this[5103] = v7;
  }
  v8 = *((_DWORD *)this + 5136);
  v9 = (double)(v8 + 1) * 0.015;
  if ( this[5102] > (double)this[5097] )
  {
    v10 = this[5102] - this[5097];
    if ( v10 < 1.0 )
      v10 = 1.0;
    v25 = v10 * 0.050000001;
    if ( v9 <= v25 )
      v9 = v25;
    v11 = v25 + this[5097];
LABEL_40:
    this[5097] = v11;
    goto LABEL_41;
  }
  if ( this[5103] < (double)this[5097] )
  {
    v12 = this[5097] - this[5103];
    if ( v12 < 1.0 )
      v12 = 1.0;
    v26 = v12 * 0.050000001;
    if ( v9 <= v26 )
      v9 = v26;
    v11 = this[5097] - v26;
    goto LABEL_40;
  }
LABEL_41:
  v27 = dbl_FB1D18;
  if ( this[5096] >= (double)v27 )
  {
    if ( this[5098] >= 0.0 )
    {
      if ( this[5098] > 0.0 )
      {
        if ( this[5092] <= (double)this[5097] || this[5092] >= (double)this[5103] )
        {
          this[5092] = this[5097];
        }
        else
        {
          this[5097] = this[5092];
          this[5096] = v27 + 1.0;
        }
      }
    }
    else if ( this[5092] >= (double)this[5097] || this[5092] <= (double)this[5102] )
    {
      this[5092] = this[5097];
    }
    else
    {
      this[5097] = this[5092];
      this[5096] = v27 + 1.0;
    }
  }
  else if ( fabs(this[5097] - this[5095]) > 0.1 )
  {
    v13 = *((_DWORD *)this + 5092);
    this[5096] = v27 + 1.0;
    v14 = this[5092] - this[5097];
    *((_DWORD *)this + 5097) = v13;
    this[5098] = v14;
  }
  v28 = this[5092] - this[5094];
  v15 = this[5102];
  this[5095] = v28;
  if ( v15 <= v30 )
  {
    if ( this[5103] >= (double)v30 )
    {
      v16 = v30 + v32;
      if ( v28 <= v16 )
      {
        v17 = v30 - v34;
        if ( v28 >= v17 )
          this[5095] = v30;
        else
          this[5095] = v17;
      }
      else
      {
        this[5095] = v16;
      }
    }
    else
    {
      this[5095] = v30 - v9;
    }
  }
  else
  {
    this[5095] = v9 + v30;
  }
  this[5092] = this[5095] + this[5094];
  if ( this[5111] != 0.0 )
    this[5092] = this[5111];
  v18 = *((_DWORD *)this + 5129);
  if ( v18 != 2139095039 )
    *((_DWORD *)this + 5092) = v18;
  v19 = *((_DWORD *)this + 4821);
  v35 = this[3997] - this[5149];
  v33 = this[3999] - this[5151];
  while ( 1 )
  {
    v20 = sqrt(v33 * v33 + v35 * v35);
    this[5152] = v20;
    v21 = (float *)LODWORD(this[v8 + 5046]);
    v36 = v21[9] * this[5092] + v21[38] + v20 * v21[42] - this[3997];
    v37 = v21[11] * this[5092] + v21[40] + v21[44] * this[5152] - this[3999];
    v22 = (v37 * this[5148] + v36 * this[5146]) / sqrt(v37 * v37 + v36 * v36);
    if ( v22 < 1.0 )
    {
      v29 = v22;
      v24 = acos(v29);
      if ( v37 * this[5146] - v36 * this[5148] > 0.0 )
        v24 = -v24;
      v23 = v24 / this[5160];
      if ( *((_DWORD *)this + 5192) == 6 )
        v23 = -v23;
    }
    else
    {
      v23 = 0.0;
    }
    v31 = 0.1;
    if ( v19 >= dword_FADE18 )
      v31 = 0.025;
    if ( v23 - this[5113] <= 0.1 )
    {
      if ( this[5113] - v23 > 0.1 )
        v23 = this[5113] - v31;
    }
    else
    {
      v23 = v31 + this[5113];
    }
    this[5113] = v23;
    if ( this[5113] > 1.0 )
    {
      this[5113] = 1.0;
      return;
    }
    if ( this[5113] < -1.0 )
    {
      this[5113] = -1.0;
      return;
    }
    if ( this[5113] > 1.0 || this[5113] < -1.0 )
      break;
    if ( this[5113] <= 1.0 && this[5113] >= -1.0 )
      return;
  }
  this[5113] = 0.0;
}
