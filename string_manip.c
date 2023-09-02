/**
 * @file string_manip.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdarg.h>

typedef struct string
{
    char *str;
    size_t len;
} string_t;

// function prototypes

string_t *string_new(const char *str);
void string_free(string_t *s);
void string_print(string_t *s);
void string_append(string_t *s, const char *str);
void string_append_char(string_t *s, char c);
void string_append_int(string_t *s, int n);
void string_append_float(string_t *s, float f);
void string_append_double(string_t *s, double d);
void string_append_bool(string_t *s, bool b);
void string_append_hex(string_t *s, uint32_t n);
void string_append_bin(string_t *s, uint32_t n);
void string_append_oct(string_t *s, uint32_t n);
void string_append_pointer(string_t *s, void *p);
void string_append_string(string_t *s, string_t *s2);
void string_append_format(string_t *s, const char *format, ...);
void string_append_format_va(string_t *s, const char *format, va_list args);
void string_append_format_va_list(string_t *s, const char *format, va_list args);

int main(int argc, char **argv); 

string_t *string_new(const char *str)
{
    string_t *s = (string_t *)malloc(sizeof(string_t));
    if (s == NULL)
    {
        return NULL;
    }
    s->len = strlen(str);
    s->str = (char *)malloc(s->len + 1);
    if (s->str == NULL)
    {
        free(s);
        return NULL;
    }
    strcpy(s->str, str);
    return s;
}

void string_free(string_t *s)
{
    if (s == NULL)
    {
        return;
    }
    free(s->str);
    free(s);
}

void string_print(string_t *s)
{
    if (s == NULL)
    {
        return;
    }
    printf("%s\n", s->str);
}

void string_append(string_t *s, const char *str)
{
    if (s == NULL || str == NULL)
    {
        return;
    }
    size_t len = strlen(str);
    s->str = (char *)realloc(s->str, s->len + len + 1);
    if (s->str == NULL)
    {
        return;
    }
    strcpy(s->str + s->len, str);
    s->len += len;
}

void string_append_char(string_t *s, char c)
{
    if (s == NULL)
    {
        return;
    }
    s->str = (char *)realloc(s->str, s->len + 2);
    if (s->str == NULL)
    {
        return;
    }
    s->str[s->len] = c;
    s->str[s->len + 1] = '\0';
    s->len++;
}

void string_append_int(string_t *s, int n)
{
    if (s == NULL)
    {
        return;
    }
    char buf[12];
    sprintf(buf, "%d", n);
    string_append(s, buf);
}

void string_append_float(string_t *s, float f)
{
    if (s == NULL)
    {
        return;
    }
    char buf[32];
    sprintf(buf, "%f", f);
    string_append(s, buf);
}

void string_append_double(string_t *s, double d)
{
    if (s == NULL)
    {
        return;
    }
    char buf[32];
    sprintf(buf, "%f", d);
    string_append(s, buf);
}

void string_append_bool(string_t *s, bool b)
{
    if (s == NULL)
    {
        return;
    }
    if (b)
    {
        string_append(s, "true");
    }
    else
    {
        string_append(s, "false");
    }
}

void string_append_hex(string_t *s, uint32_t n)
{
    if (s == NULL)
    {
        return;
    }
    char buf[32];
    sprintf(buf, "%x", n);
    string_append(s, buf);
}

void string_append_bin(string_t *s, uint32_t n)
{
    if (s == NULL)
    {
        return;
    }
    char buf[32];
    sprintf(buf, "%b", n);
    string_append(s, buf);
}

void string_append_oct(string_t *s, uint32_t n)
{
    if (s == NULL)
    {
        return;
    }
    char buf[32];
    sprintf(buf, "%o", n);
    string_append(s, buf);
}

void string_append_pointer(string_t *s, void *p)
{
    if (s == NULL)
    {
        return;
    }
    char buf[32];
    sprintf(buf, "%p", p);
    string_append(s, buf);
}

void string_append_string(string_t *s, string_t *s2)
{
    if (s == NULL || s2 == NULL)
    {
        return;
    }
    string_append(s, s2->str);
}

void string_append_format(string_t *s, const char *format, ...)
{
    if (s == NULL || format == NULL)
    {
        return;
    }
    va_list args;
    va_start(args, format);
    string_append_format_va(s, format, args);
    va_end(args);
}

void string_append_format_va(string_t *s, const char *format, va_list args)
{
    if (s == NULL || format == NULL)
    {
        return;
    }
    // Make a copy of the va_list to avoid affecting the original
    va_list args_copy;
    va_copy(args_copy, args);

    char buf[1024];
    vsprintf(buf, format, args_copy);
    string_append(s, buf);

    // Clean up the copied va_list
    va_end(args_copy);
}

void string_append_format_va_list(string_t *s, const char *format, va_list args)
{
    if (s == NULL || format == NULL)
    {
        return;
    }
    char buf[1024];
    vsprintf(buf, format, args);
    string_append(s, buf);
}

int main(int argc, char **argv)
{
    string_t *s = string_new("Hello");
    string_append(s, " World!");
    string_print(s);
    string_append_char(s, '!');
    string_print(s);
    string_append_int(s, 123);
    string_print(s);
    string_append_float(s, 123.456);
    string_print(s);
    string_append_double(s, 123.456);
    string_print(s);
    string_append_bool(s, true);
    string_print(s);
    string_append_hex(s, 0x12345678);
    string_print(s);
    string_append_bin(s, 0b10101010);
    string_print(s);
    string_append_oct(s, 01234567);
    string_print(s);
    string_append_pointer(s, s);
    string_print(s);
    string_t *s2 = string_new("Hello");
    string_append_string(s, s2);
    string_print(s);
    string_append_format(s, "Hello %s %d %f %p", "World", 123, 123.456, s);
    string_print(s);
    string_free(s);
    string_free(s2);
    return 0;
}


