/**
 * @file template.c
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

typedef struct template
{
    char *str;
    size_t len;
} template_t;

// function prototypes

template_t *template_new(const char *str);
void template_free(template_t *s);
void template_print(template_t *s);
void template_append(template_t *s, const char *str);
void template_append_char(template_t *s, char c);
void template_append_int(template_t *s, int n);
void template_append_float(template_t *s, float f);
void template_append_double(template_t *s, double d);
void template_append_bool(template_t *s, bool b);
void template_append_hex(template_t *s, uint32_t n);
void template_append_bin(template_t *s, uint32_t n);
void template_append_oct(template_t *s, uint32_t n);
void template_append_pointer(template_t *s, void *p);
void template_append_template(template_t *s, template_t *s2);
void template_append_format(template_t *s, const char *format, ...);
void template_append_format_va(template_t *s, const char *format, va_list args);
void template_append_format_va_list(template_t *s, const char *format, va_list args);

int main(int argc, char **argv);

template_t *template_new(const char *str)
{
    template_t *s = (template_t *)malloc(sizeof(template_t));
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

void template_free(template_t *s)
{
    free(s->str);
    free(s);
}
void template_print(template_t *s)
{
    printf("%s", s->str);
}
void template_append(template_t *s, const char *str)
{
    size_t len = strlen(str);
    s->str = (char *)realloc(s->str, s->len + len + 1);
    if (s->str == NULL)
    {
        return;
    }
    strcpy(s->str + s->len, str);
    s->len += len;
}
void template_append_char(template_t *s, char c)
{
    s->str = (char *)realloc(s->str, s->len + 2);
    if (s->str == NULL)
    {
        return;
    }
    s->str[s->len] = c;
    s->str[s->len + 1] = '\0';
    s->len++;
}
void template_append_int(template_t *s, int n)
{
    char buf[12];
    sprintf(buf, "%d", n);
    template_append(s, buf);
}
void template_append_float(template_t *s, float f)
{
    char buf[12];
    sprintf(buf, "%f", f);
    template_append(s, buf);
}
void template_append_double(template_t *s, double d)
{
    char buf[12];
    sprintf(buf, "%f", d);
    template_append(s, buf);
}
void template_append_bool(template_t *s, bool b)
{
    if (b)
    {
        template_append(s, "true");
    }
    else
    {
        template_append(s, "false");
    }
}
void template_append_hex(template_t *s, uint32_t n)
{
    char buf[12];
    sprintf(buf, "%x", n);
    template_append(s, buf);
}
void template_append_bin(template_t *s, uint32_t n)
{
    char buf[12];
    sprintf(buf, "%b", n);
    template_append(s, buf);
}
void template_append_oct(template_t *s, uint32_t n)
{
    char buf[12];
    sprintf(buf, "%o", n);
    template_append(s, buf);
}
void template_append_pointer(template_t *s, void *p)
{
    char buf[12];
    sprintf(buf, "%p", p);
    template_append(s, buf);
}
void template_append_template(template_t *s, template_t *s2)
{
    template_append(s, s2->str);
}
void template_append_format(template_t *s, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    template_append_format_va_list(s, format, args);
    va_end(args);
}
void template_append_format_va(template_t *s, const char *format, va_list args)
{
    template_t *s2 = template_new("");
    if (s2 == NULL)
    {
        return;
    }
    vsprintf(s2->str, format, args);
    template_append(s, s2->str);
    template_free(s2);
}
void template_append_format_va_list(template_t *s, const char *format, va_list args)
{
    template_t *s2 = template_new("");
    if (s2 == NULL)
    {
        return;
    }
    vsprintf(s2->str, format, args);
    template_append(s, s2->str);
    template_free(s2);
}

int main(int argc, char **argv)
{
    template_t *s = template_new("Hello, ");
    template_append(s, "world!\n");
    template_print(s);
    template_free(s);
    return 0;
}

// Path: template.c