# Readability 

Reading Levels
According to Scholastic, E.B. White’s “Charlotte’s Web” is between a second and fourth grade reading level, and Lois Lowry’s “The Giver” is between an eighth grade reading level and a twelfth grade reading level. What does it mean, though, for a book to be at a “fourth grade reading level”?

Well, in many cases, a human expert might read a book and make a decision on the grade for which they think the book is most appropriate. But you could also imagine an algorithm attempting to figure out what the reading level of a text is.

So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too. A number of “readability tests” have been developed over the years, to give a formulaic process for computing the reading level of a text.

One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text. The formula is:

index = 0.0588 * L - 0.296 * S - 15.8
Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

Let’s write a program called readability that takes a text and determines its reading level. For example, if user types in a line from Dr. Seuss:

<pre class="highlight"><code>$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
</code></pre>

The text the user inputted has 65 letters, 4 sentences, and 14 words. 65 letters per 14 words is an average of about 464.29 letters per 100 words. And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words. Plugged into the Coleman-Liau formula, and rounded to the nearest whole number, we get an answer of 3: so this passage is at a third grade reading level.


<p>Let’s try another one:</p>

<pre class="highlight"><code>$ ./readability
Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.
Grade 5
</code></pre>

This text has 214 letters, 4 sentences, and 56 words. That comes out to about 382.14 letters per 100 words, and 7.14 sentences per 100 words. Plugged into the Coleman-Liau formula, we get a fifth grade reading level.

As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an eleventh grade reading level.


<pre class="highlight"><code>$ ./readability
Text: As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an eleventh grade reading level.
Grade 11
</code></pre>

<h2 id="specification"><a data-id="" href="#specification">Specification</a></h2>

<p>Design and implement a program, <code class="highlighter-rouge">readability</code>, that computes the Coleman-Liau index of the text.</p>

<ul class="fa-ul">
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Implement your program in a file called <code class="highlighter-rouge">readability.c</code> in a <code class="highlighter-rouge">~/pset2/readability</code> directory.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Your program must prompt the user for a <code class="highlighter-rouge">string</code> of text (using <code class="highlighter-rouge">get_string</code>).</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from <code class="highlighter-rouge">a</code> to <code class="highlighter-rouge">z</code> or any uppercase character from <code class="highlighter-rouge">A</code> to <code class="highlighter-rouge">Z</code>, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Your program should print as output <code class="highlighter-rouge">"Grade X"</code> where <code class="highlighter-rouge">X</code> is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output <code class="highlighter-rouge">"Grade 16+"</code> instead of giving the exact index number. If the index number is less than 1, your program should output <code class="highlighter-rouge">"Before Grade 1"</code>.</li>
</ul>
